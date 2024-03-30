// 연결 리스트 > 1.에디터
// <에디터 동작들> L : 커서를 왼쪽으로 옮김 D : 커서를 오른쪽으로 옯김 B : 커서 왼쪽 문자 삭제 P x : x 라는 문자 왼쪽 추가
// => 커서를 포인터로 표현하고 문자들을 연결리스트로 구현(양방향)
// sol
// 1>
// 2> 커서를 문자열안에 삽입해서 연결리스트를 
// 3> 스택으로 푸는 방법

// [C++]
// c++ 에서는 포인터를 전달해도 값이 바뀌지 않는다
// 그렇기에 값을 변경하기 위해서는 (&)참조로 전달해야 한다.
// 클래스 생성 방법 => DLinkedList<char> list;
// 자바에서 사용하는 new 방법은 클래스 포인터 생성할 때 사용(동적 생성)
// 포인터에 널값을 할당하기 위해서는 nullptr 사용

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

// 이 탬플릿 맨날 써줘야함...?
template <typename E>
void DLinkedList<E>::push_back(E data) {
	// 구조체의 포인터로 생성하는 것과 그냥 구조체 생성하는 것과 무엇이 다름?
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
}



int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	string init;
	cin >> init;
	DLinkedList<char> list;
	
	for (int i = 0; i < init.size(); i++) {
		list.push_back(init[i]);
	}

	int cnt;
	cin >> cnt;
	char cmd;
	// cur 선언
	node<char>* cur = list.end;
	for (int i = 0; i < cnt; i++) {
		cin >> cmd;
		switch (cmd)
		{
		case 'L':
			// 커서 왼쪽으로 옮김
			if(cur->prev != list.head) cur = cur->prev;
			//cout << "커서: " << cur->data << "\n";
			break;
		case 'D':
			// 오른쪽으로 옮김
			if (cur->next != nullptr) cur = cur->next;
			//cout << "커서: " << cur->data << "\n";
			break;
		case 'B':
			// 왼쪽에 있는 문자 삭제
			list.pop(cur);
			//list.allPrint();
			//cout << "\n커서: " << cur->data << "\n";
			break;
		case 'P':
			char ch;
			cin >> ch;
			list.insert(cur, ch);
			//list.allPrint();
			//cout << "\n커서: " << cur->data << "\n";
			break;
		default:
			break;
		}
	}

	list.allPrint();


}