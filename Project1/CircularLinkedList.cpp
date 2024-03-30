// 원형 연결리스트 
// head와 end 가 서로를 가리킴

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
	void push_front(E data);
	// 삭제(앞, 뒤)
	E pop_back();
	E pop_frcont();
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

