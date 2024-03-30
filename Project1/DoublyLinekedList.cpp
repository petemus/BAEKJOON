// node 클래스를 만들어도 될듯
// node의 데이터 타입도 추상화를 할 수 있을 것 같은데 기억이 안남 ㅇㅅㅇ 
// 연결리스트 헤더파일을 만들어서 필요할 떄마다 include 해도 됤듯
// ?? malloc은 동적할당을 하기 위한 함수 근데 new 함수를 통해 동적생성을 하면 malloc은 왜 필요??


#include<iostream>
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
		size = 0;
	}
	// 삽입(앞, 뒤)
	void push_back(E data);
	void push_front(E data);
	// 문제 한정 함수 : 가리키는 위치의 왼쪽에 데이터 삽입 ( cur는 head는 불가능 but end는 가능
	void insert(node<E>*& cur, E data);
	// 삭제(앞, 뒤)
	E pop_back();
	E pop_front();
	// * 문제 한정 함수 : 가리키는 위치에 왼쪽 노드 pop
	E pop(node<E>*& cur);
	// 전체 출력
	void allPrint();

};

// 이 탬플릿 맨날 써줘야함...?
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

template <typename E>
void DLinkedList<E>::push_front(E data) {
	node<E>* newnode = new node<E>(data);
	newnode->prev = head;
	newnode->next = head->next;
	head->next->prev = newnode;
	head->next = newnode;
	size++;
}

// 커서 왼쪽에 삽입
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

template <typename E>
E DLinkedList<E>::pop_back() {
	// 연결리스트에 값이 없으면 그냥 리턴
	if (head->next == end) return;
	node<E>* delnode = end->prev;
	delnode->prev->next = end;
	end->prev = delnode->prev;
	delnode->prev = nullptr;
	delnode->next = nullptr;
	size--;
	return delnode->data;
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
		cout << now->data << " ";
		now = now->next;

	}
}




