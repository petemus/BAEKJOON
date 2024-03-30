// ���� > 3.���� ����(1874��)

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
	int seq = 0;
	int i = 1;

	vector<char> sequence;
	bool isFail = false;

	// ���� ���� : ���ÿ� ���� ���ų� �����ϼ��� �Ұ����Ҷ�
	for(int k = 0; k < n; k++){
		cin >> seq;
		if (i < seq) {
			while (seq != i) {
				// �̷� push
				stack.push(i++);
				sequence.push_back('+');
			}
		}
		if (i == seq) {
			// push �� pop
			stack.push(i++);
			sequence.push_back('+');
			stack.pop();
			sequence.push_back('-');
			continue;
		}
		if (i > seq) {
			int tmp;
			tmp = stack.peek();
			if (tmp != seq) {
				// ����
				isFail = true;
				break;
			}
			else {
				// ����
				sequence.push_back('-');
				stack.pop();
				continue;
			}
		}
	}

	if (isFail) {
		cout << "NO";	
	}
	else {
		for (int i = 0; i < sequence.size(); i++) {
			cout << sequence[i] << "\n";
		}
	}


}



