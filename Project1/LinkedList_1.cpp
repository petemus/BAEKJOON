// ���� ����Ʈ > 1.������
// <������ ���۵�> L : Ŀ���� �������� �ű� D : Ŀ���� ���������� ���� B : Ŀ�� ���� ���� ���� P x : x ��� ���� ���� �߰�
// => Ŀ���� �����ͷ� ǥ���ϰ� ���ڵ��� ���Ḯ��Ʈ�� ����(�����)
// sol
// 1>
// 2> Ŀ���� ���ڿ��ȿ� �����ؼ� ���Ḯ��Ʈ�� 
// 3> �������� Ǫ�� ���

// [C++]
// c++ ������ �����͸� �����ص� ���� �ٲ��� �ʴ´�
// �׷��⿡ ���� �����ϱ� ���ؼ��� (&)������ �����ؾ� �Ѵ�.
// Ŭ���� ���� ��� => DLinkedList<char> list;
// �ڹٿ��� ����ϴ� new ����� Ŭ���� ������ ������ �� ���(���� ����)
// �����Ϳ� �ΰ��� �Ҵ��ϱ� ���ؼ��� nullptr ���

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

// �� ���ø� �ǳ� �������...?
template <typename E>
void DLinkedList<E>::push_back(E data) {
	// ����ü�� �����ͷ� �����ϴ� �Ͱ� �׳� ����ü �����ϴ� �Ͱ� ������ �ٸ�?
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
	// cur ����
	node<char>* cur = list.end;
	for (int i = 0; i < cnt; i++) {
		cin >> cmd;
		switch (cmd)
		{
		case 'L':
			// Ŀ�� �������� �ű�
			if(cur->prev != list.head) cur = cur->prev;
			//cout << "Ŀ��: " << cur->data << "\n";
			break;
		case 'D':
			// ���������� �ű�
			if (cur->next != nullptr) cur = cur->next;
			//cout << "Ŀ��: " << cur->data << "\n";
			break;
		case 'B':
			// ���ʿ� �ִ� ���� ����
			list.pop(cur);
			//list.allPrint();
			//cout << "\nĿ��: " << cur->data << "\n";
			break;
		case 'P':
			char ch;
			cin >> ch;
			list.insert(cur, ch);
			//list.allPrint();
			//cout << "\nĿ��: " << cur->data << "\n";
			break;
		default:
			break;
		}
	}

	list.allPrint();


}