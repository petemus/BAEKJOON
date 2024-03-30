// node Ŭ������ ���� �ɵ�
// node�� ������ Ÿ�Ե� �߻�ȭ�� �� �� ���� �� ������ ����� �ȳ� ������ 
// ���Ḯ��Ʈ ��������� ���� �ʿ��� ������ include �ص� ���
// ?? malloc�� �����Ҵ��� �ϱ� ���� �Լ� �ٵ� new �Լ��� ���� ���������� �ϸ� malloc�� �� �ʿ�??


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

	// ������
	DLinkedList() {
		head = new node<E>;
		end = new node<E>;
		head->next = end;
		head->prev = nullptr;
		// c++ ���� �� �� �Ҵ��� nullptr
		end->prev = head;
		end->next = nullptr;
		size = 0;
	}
	// ����(��, ��)
	void push_back(E data);
	void push_front(E data);
	// ���� ���� �Լ� : ����Ű�� ��ġ�� ���ʿ� ������ ���� ( cur�� head�� �Ұ��� but end�� ����
	void insert(node<E>*& cur, E data);
	// ����(��, ��)
	E pop_back();
	E pop_front();
	// * ���� ���� �Լ� : ����Ű�� ��ġ�� ���� ��� pop
	E pop(node<E>*& cur);
	// ��ü ���
	void allPrint();

};

// �� ���ø� �ǳ� �������...?
template <typename E>
void DLinkedList<E>::push_back(E data) {
	// ����ü�� �����ͷ� �����ϴ� �Ͱ� �׳� ����ü �����ϴ� �Ͱ� ������ �ٸ�
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

// Ŀ�� ���ʿ� ����
// Ŀ�� ���ʿ� ����
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
	// ���Ḯ��Ʈ�� ���� ������ �׳� ����
	if (head->next == end) return;
	node<E>* delnode = end->prev;
	delnode->prev->next = end;
	end->prev = delnode->prev;
	delnode->prev = nullptr;
	delnode->next = nullptr;
	size--;
	return delnode->data;
}

// ����Ű�� ���뿡 ���� pop 
// cur = head->next �ΰ�� ���
template <typename E>
E DLinkedList<E>::pop(node<E>*& cur) {
	// ���Ḯ��Ʈ�� ���� ������ �׳� ����
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




