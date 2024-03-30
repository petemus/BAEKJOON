// ���� > 4.ž(2493��)
// ó������ ���ÿ� �����鼭 ��
// ������ ���� ���� ������ ũ�� �������� ����ؼ� pop ũ�� �� �� ������� ����
// and ���ÿ� push

#include <iostream>
#include <vector>
using namespace std;

template <typename E>
class Stack {
private:
	int top;
	vector<E> stack;
	vector<int> index;
public:
	int length;
	Stack() {
		top = -1;
		length = 0;
	}
	void push(E element);
	E pop();
	int size();
	bool isEmpty();
	E peek();
	int peek(int k);
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	Stack<int> tower;
	// ��� ���� �迭
	int* result = new int[n];
	int tmp = 0;
	int comp = 0;
	Stack<int> index;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (tower.size() == 0) {
			// ������ ��������� �׳� push
			tower.push(tmp);
			index.push(i + 1);
			result[i] = 0;
		}
		else {
			// ��ġ �����ϴ� ����� �̰� ������
			while (true) {
				if (tower.size() == 0) {
					result[i] = 0;
					tower.push(tmp);
					index.push(i + 1);
					break;
				}
				 comp = tower.peek();
				if (comp >= tmp) {
					result[i] = index.peek();
					tower.push(tmp);
					index.push(i + 1);
					break;
				}
				else {
					tower.pop();
					index.pop();
				}
			}
			
		}
	}

	
	for (int i = 0; i < n; i++) {
		cout << result[i] << " ";
	}

}

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

