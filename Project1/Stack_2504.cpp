// Stack > ��ȣ�� �� (2504��)
// Ǯ�� �ð� : 50 m
// �߸��� ��ȣ ó���� �߿� 

// ! stack���� peek�� �ϰų� pop�� �Ҷ� stack�� ����ִ� ��츦 �׻� �����ؾ��� 
// ! �߸��� ��ȣ�� ���� ���� ó���� �� ������� 
// -> 1) ��ȣ�� ���� �ִ� ���
// -> 2) )]�ε� ������ ����ִ� ��� -> seqmentation fault 

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
			// ( �� ���ö����� �ݺ�

			int num = 0;
			while (true)
			{
				if (parenthesis.empty())
				{
					// stack�� ��������� �߸��� ��ȣ�� 
					cout << 0;
					return 0;
				}

				char t = parenthesis.top();
				if (t == '[')
				{
					// �߸��� ��ȣ��
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
			// [ �� ���ö����� �ݺ�
			int num = 0;
			while (true)
			{
				if (parenthesis.empty())
				{
					// stack�� ��������� �߸��� ��ȣ�� 
					cout << 0;
					return 0;
				}

				char t = parenthesis.top();
				if (t == '(')
				{
					// �߸��� ��ȣ��
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

	// pth�� 'N'���� �ٸ� ��ȣ�� ���������� ����
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
	// �������� nums�� �ִ� �� �� ���ؼ� ��ȯ
	int result = 0;
	s = nums.size();
	// size pop���ֹǷ� ��� ����
	for (int i = 0; i < s; i++)
	{
		result += nums.top(); nums.pop();
	}
	cout << result;
}