// 연결리스트 > 3.요세푸스의 문제
// 대충 3칸씩 움직이면서 삭제하는 듯
// 원형 연결리스트로 만들어야할듯
// index 이동 후 pop하는 함수, 뒤에 삽입하는 함수, 필요

// sol1>
// sol2> queue를 통해서 3만큼 이동하면 pop 아니면 뒤로 push를 queue가 빌때까지 반복



#include<iostream>
using namespace std;

template <typename E>
struct node
{
	node(E d) : data(d) {}
	node() {}
	E data;
	node<E>* next;
	node<E>* prev;
};

template <typename E>
class CLinkedList {

private:
public:
	int size;
	node<E>* endnode;
	node<E>* headnode;

	// 생성자
	CLinkedList() {
		headnode = nullptr;
		size = 0;
	}
	// 삽입(앞, 뒤)
	void push_back(E data);
	// 삭제(앞, 뒤)
	// * 문제 한정 함수 : 가리키는 위치에서 k만큼 이동후 삭제 (head와 end는 무시)
	E pop(node<E>*& cur, int k);
	// 전체 출력
	void allPrint();
};

template <typename E>
void CLinkedList<E>::push_back(E data) {
	if (headnode == nullptr) {
		// 리스트가 비어있으면 
		node<E>* newnode = new node<E>(data);
		newnode->next = newnode->prev = newnode;
		headnode = endnode = newnode;
		return;
	}
	node<E>* newnode = new node<E>(data);
	newnode->next = headnode;
	newnode->prev = endnode;
	endnode->next = newnode;
	headnode->prev = newnode;
	endnode = newnode;
	size++;
}


template <typename E>
E CLinkedList<E>::pop(node<E>*& cur, int k) {
	// 연결리스트에 값이 없으면 그냥 리턴
	if (headnode == nullptr) return NULL;
	if (headnode == endnode) {
		// 노드가 한 개 밖에 없으면
		node<E>* delnode = cur;
		headnode = endnode = cur = nullptr;
		size--;
		return delnode->data;
	}
	node<E>* delnode = cur;
	for (int i = 0; i < k; i++) {
		delnode = delnode->next;
	}
	delnode->prev->next = delnode->next;
	delnode->next->prev = delnode->prev;
	cur = delnode->next;
	size--;

	if (delnode == headnode) headnode = cur;
	else if (delnode == endnode) endnode = delnode->prev;

	return delnode->data;
}

template<typename E>
void CLinkedList<E>::allPrint()
{
	if (headnode == nullptr) return;
	node<E>* now = headnode;
	do {
		cout << now->data << " ";
		now = now->next;
	} while (now != headnode);
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	// 리스트 초기화
	CLinkedList<int>* list = new CLinkedList<int>;
	for (int i = 0; i < n; i++) {
		list->push_back(i + 1);
	}
	//list->allPrint();
	node<int>* cur = list->headnode;
	cout << "<";
	while (list->headnode != nullptr) {
		cout << list->pop(cur, k - 1);
		if (list->headnode != nullptr) {
			cout << ", ";
		}
		//int m = list->pop(cur, k - 1);
		//cout << m << "   ";
		//list->allPrint();
		//cout << "H: " << list->headnode->data << " E: " << list->endnode->data << " C: " << cur->data << "\n";
	}
	cout << ">";
}
