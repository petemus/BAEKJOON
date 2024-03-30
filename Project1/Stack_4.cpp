// 스택 > 4.탑(2493번)
// 처음부터 스택에 넣으면서 비교
// 들어오는 값이 이전 값보다 크면 이전값들 계속해서 pop 크면 그 값 결과값에 저장
// and 스택에 push

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
	// 결과 저장 배열
	int* result = new int[n];
	int tmp = 0;
	int comp = 0;
	Stack<int> index;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (tower.size() == 0) {
			// 스택이 비어있으면 그냥 push
			tower.push(tmp);
			index.push(i + 1);
			result[i] = 0;
		}
		else {
			// 위치 저장하는 방법이 이게 맞을까
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

