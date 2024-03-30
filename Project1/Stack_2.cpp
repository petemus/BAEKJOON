// ���� > 2.����

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
	// k ��°�� ��� ��ȯ
	E peek(int k);
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

template<typename E>
E Stack<E>::peek(int k)
{
	return stack[k];
}

int main() {

	int n;
	cin >> n;

	Stack<int> stack;
	int data = 0;
	for (int i = 0; i < n; i++) {
		cin >> data;
		if (data == 0) stack.pop();
		else stack.push(data);
	}

	int sum = 0;
	for (int i = 0; i < stack.size(); i++) {
		data = stack.peek(i);
		sum += data;
	}
	cout << sum;
}
