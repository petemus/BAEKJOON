// 스택 > 1.스택
// 스택 구현 문제
// 필요 기능 -> push x, pop, size, empty, top

// [c++]
// string::compare() 함수는 같으면 0을 반환  ㅎㅎ;;

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
	// vector는 값 넣을 때는 []로 접근 불가
	top++;
	stack.push_back(element);
	length++;
}

template<typename E>
E Stack<E>::pop()
{
	// stack이 비었으면 정수 -1을 출력
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
	// 값이 없으면
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
		// ?? 문자열을 스위치문에 넣는 방법은 없나
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
