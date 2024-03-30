// ���Ḯ��Ʈ > 3.�似Ǫ���� ����
// ���� 3ĭ�� �����̸鼭 �����ϴ� ��
// ���� ���Ḯ��Ʈ�� �������ҵ�
// index �̵� �� pop�ϴ� �Լ�, �ڿ� �����ϴ� �Լ�, �ʿ�

// sol1>
// sol2> queue�� ���ؼ� 3��ŭ �̵��ϸ� pop �ƴϸ� �ڷ� push�� queue�� �������� �ݺ�



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
	// ����(��, ��)
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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	// ����Ʈ �ʱ�ȭ
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
