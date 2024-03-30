// ���� ���Ḯ��Ʈ 
// head�� end �� ���θ� ����Ŵ

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

	// ������
	CLinkedList() {
		headnode = nullptr;
		size = 0;
	}
	// ����(��, ��)
	void push_back(E data);
	void push_front(E data);
	// ����(��, ��)
	E pop_back();
	E pop_frcont();
	// * ���� ���� �Լ� : ����Ű�� ��ġ���� k��ŭ �̵��� ���� (head�� end�� ����)
	E pop(node<E>*& cur, int k);
	// ��ü ���
	void allPrint();

};

template <typename E>
void CLinkedList<E>::push_back(E data) {
	if (headnode == nullptr) {
		// ����Ʈ�� ��������� 
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
	// ���Ḯ��Ʈ�� ���� ������ �׳� ����
	if (headnode == nullptr) return NULL;
	if (headnode == endnode) {
		// ��尡 �� �� �ۿ� ������
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

