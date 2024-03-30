// 연결 리스트 > 2.키로거
// 에디터 문제랑 비슷
#include <iostream>
using namespace std;

template <typename E>
struct node
{
	node(E d) : data(d) {}
	node() {}
	node* prev;
	E data;
	node* next;
};

template <typename E>
class DLinkedList {

private:
public:
	int size;
	node<E>* end;
	node<E>* head;

	// 생성자
	DLinkedList() {
		head = new node<E>;
		end = new node<E>;
		head->next = end;
		head->prev = nullptr;
		// c++ 에서 널 값 할당은 nullptr
		end->prev = head;
		end->next = nullptr;
	}
	// 삽입(앞, 뒤)
	void push_back(E data);
	// 문제 한정 함수 : 가리키는 위치의 왼쪽에 데이터 삽입 ( cur는 head는 불가능 but end는 가능
	void insert(node<E>*& cur, E data);
	// * 문제 한정 함수 : 가리키는 위치에 왼쪽 노드 pop
	E pop(node<E>*& cur);
	// 전체 출력
	void allPrint();

};

template <typename E>
void DLinkedList<E>::push_back(E data) {
	// 구조체의 포인터로 생성하는 것과 그냥 구조체 생성하는 것과 무엇이 다름
	node<E>* newnode = new node<E>(data);
	newnode->prev = end->prev;
	newnode->next = end;
	end->prev->next = newnode;
	end->prev = newnode;
	size++;
}


// 커서 왼쪽에 삽입
template <typename E>
void DLinkedList<E>::insert(node<E>*& cur, E data) {
	node<E>* newnode = new node<E>(data);
	newnode->prev = cur->prev;
	newnode->next = cur;
	cur->prev->next = newnode;
	cur->prev = newnode;
	cur = newnode->next;
	size++;
}

// 가리키는 위취에 왼쪽 pop 
// cur = head->next 인경우 고려
template <typename E>
E DLinkedList<E>::pop(node<E>*& cur) {
	// 연결리스트에 값이 없으면 그냥 리턴
	if (head->next == end) return NULL;
	node<E>* delnode = cur->prev;
	if (delnode == head) return NULL;
	delnode->prev->next = delnode->next;
	delnode->next->prev = delnode->prev;
	delnode->prev = nullptr;
	delnode->next = nullptr;
	size--;
	return delnode->data;
}

template<typename E>
void DLinkedList<E>::allPrint()
{
	node<E>* now = head->next;
	while (now != end) {
		cout << now->data;
		now = now->next;
	}
	cout << "\n";
}



int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int testcase = 0;
	cin >> testcase;
	string str;
	node<char>* cur;
	for (int i = 0; i < testcase; i++) {
		cin >> str;
		DLinkedList<char> list;
		cur = list.end;
		for (int i = 0; i < str.size(); i++) {
			switch (str[i])
			{
			case '<':
				// 커서 왼쪽으로 옮김
				if (cur->prev != list.head) cur = cur->prev;
				//cout << "커서: " << cur->data << "\n";
				break;
			case '>':
				// 오른쪽으로 옮김
				if (cur->next != nullptr) cur = cur->next;
				//cout << "커서: " << cur->data << "\n";
				break;
			case '-':
				// 왼쪽에 있는 문자 삭제
				list.pop(cur);
				//list.allPrint();
				//cout << "\n커서: " << cur->data << "\n";
				break;
			default:
				// 일반 문자가 들어올 경우
				list.insert(cur, str[i]);
				//list.allPrint();
				//cout << "\n커서: " << cur->data << "\n";
				break;
			}
		}
		list.allPrint();
	}

	


	



}