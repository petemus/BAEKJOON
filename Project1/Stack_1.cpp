// ���� > 1.����
// ���� ���� ����
// �ʿ� ��� -> push x, pop, size, empty, top

// [c++]
// string::compare() �Լ��� ������ 0�� ��ȯ  ����;;

#include <iostream>
#include <vector>
using namespace std;

template <typename E>
class Stack {
private:
	int top;
	vector<E> stack;
public:
	int length;
	Stack() {
		top = -1;
		length = 0;
		//stack = new vector<E>();
	}
	void push(E element);
	E pop();
	int size();
	bool isEmpty();
	E peek();
};

template<typename E>
void Stack<E>::push(E element)
{
	// vector�� �� ���� ���� []�� ���� �Ұ�
	top++;
	stack.push_back(element);
	length++;
}

template<typename E>
E Stack<E>::pop()
{
	// stack�� ������� ���� -1�� ���
	if (top == -1) return E(-1);
	E tmp = stack[top--];
	length--;
	stack.pop_back();
	return tmp;
}


template<typename E>
int Stack<E>::size()
{
	return length;
}

template<typename E>
bool Stack<E>::isEmpty()
{
	if (top == -1) return true;
	else return false;
}

template<typename E>
E Stack<E>::peek()
{
	// ���� ������
	if (top == -1) return E(-1);
	return stack[top];
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	Stack<int> stack;
	string cmd;

	
	for (int i = 0; i < n; i++) {
		cin >> cmd;
		// ?? ���ڿ��� ����ġ���� �ִ� ����� ����
		if (cmd.compare("push") == 0) {
			int data;
			cin >> data;
			stack.push(data);
		}
		else if (cmd.compare("pop") == 0) {
			cout << stack.pop() << "\n";
		}
		else if (cmd.compare("size") == 0) {
			cout << stack.size() << "\n";
		}
		else if (cmd.compare("empty") == 0) {
			cout << stack.isEmpty() << "\n";
		}
		else if (cmd.compare("top") == 0) {
			cout << stack.peek() << "\n";
		}
	}
}
