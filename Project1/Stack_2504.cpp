// Stack > 괄호의 값 (2504번)
// 풀이 시간 : 50 m
// 잘못된 괄호 처리가 중요 

// ! stack에서 peek을 하거나 pop을 할때 stack이 비어있는 경우를 항상 생각해야함 
// ! 잘못된 괄호에 대한 예외 처리를 잘 해줘야함 
// -> 1) 괄호가 남아 있는 경우
// -> 2) )]인데 스택이 비어있는 경우 -> seqmentation fault 

#include <iostream>
#include <stack>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	stack<int> nums;
	stack<char> parenthesis;

	string input;
	cin >> input;

	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == '(' || input[i] == '[') parenthesis.push(input[i]);
		else if (input[i] == ')')
		{
			// ( 이 나올때까지 반복

			int num = 0;
			while (true)
			{
				if (parenthesis.empty())
				{
					// stack이 비어있으면 잘못된 괄호열 
					cout << 0;
					return 0;
				}

				char t = parenthesis.top();
				if (t == '[')
				{
					// 잘못된 괄호열
					cout << 0;
					return 0;
				}
				else if (t == 'N')
				{
					num += nums.top(); nums.pop();
					parenthesis.pop();
				}
				else if(t == '(')
				{
					if (num == 0) num = 1;
					nums.push(num * 2);
					parenthesis.pop();
					parenthesis.push('N');
					break;
				}
			}
		}
		else if (input[i] == ']')
		{
			// [ 이 나올때까지 반복
			int num = 0;
			while (true)
			{
				if (parenthesis.empty())
				{
					// stack이 비어있으면 잘못된 괄호열 
					cout << 0;
					return 0;
				}

				char t = parenthesis.top();
				if (t == '(')
				{
					// 잘못된 괄호열
					cout << 0;
					return 0;
				}
				else if (t == 'N')
				{
					num += nums.top(); nums.pop();
					parenthesis.pop();
				}
				else if (t == '[')
				{
					if (num == 0) num = 1;
					nums.push(num * 3);
					parenthesis.pop();
					parenthesis.push('N');
					break;
				}
			}
		}
	}

	// pth에 'N'말고 다른 괄호가 남아있으면 오류
	int s = parenthesis.size();
	for (int i = 0; i < s; i++)
	{
		char t = parenthesis.top();
		if (t != 'N')
		{
			cout << 0;
			return 0;
		}
		else parenthesis.pop();
	}
	// 마지막에 nums에 있는 것 다 더해서 반환
	int result = 0;
	s = nums.size();
	// size pop해주므로 계속 변동
	for (int i = 0; i < s; i++)
	{
		result += nums.top(); nums.pop();
	}
	cout << result;
}