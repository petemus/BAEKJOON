// ���� ����Ʈ > 2.Ű�ΰ�
// ������ ������ ���
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

	// ������
	DLinkedList() {
		head = new node<E>;
		end = new node<E>;
		head->next = end;
		head->prev = nullptr;
		// c++ ���� �� �� �Ҵ��� nullptr
		end->prev = head;
		end->next = nullptr;
	}
	// ����(��, ��)
	void push_back(E data);
	// ���� ���� �Լ� : ����Ű�� ��ġ�� ���ʿ� ������ ���� ( cur�� head�� �Ұ��� but end�� ����
	void insert(node<E>*& cur, E data);
	// * ���� ���� �Լ� : ����Ű�� ��ġ�� ���� ��� pop
	E pop(node<E>*& cur);
	// ��ü ���
	void allPrint();

};

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
				// Ŀ�� �������� �ű�
				if (cur->prev != list.head) cur = cur->prev;
				//cout << "Ŀ��: " << cur->data << "\n";
				break;
			case '>':
				// ���������� �ű�
				if (cur->next != nullptr) cur = cur->next;
				//cout << "Ŀ��: " << cur->data << "\n";
				break;
			case '-':
				// ���ʿ� �ִ� ���� ����
				list.pop(cur);
				//list.allPrint();
				//cout << "\nĿ��: " << cur->data << "\n";
				break;
			default:
				// �Ϲ� ���ڰ� ���� ���
				list.insert(cur, str[i]);
				//list.allPrint();
				//cout << "\nĿ��: " << cur->data << "\n";
				break;
			}
		}
		list.allPrint();
	}

	


	



}