//���ڿ� ���� ����
//�ð� ���� : 1��
//������ �䳢�� ���ڿ��� ���� ���� �����Ϸ��� �մϴ�.
//������� ���� ���ڿ� S�� �־����� ��, �� ���ڿ� �� � �κ� ���ڿ��� K(Q)�� ���� ������ �� �ֽ��ϴ�.�̰��� Q��� ���ڿ��� K �� �ݺ��ȴٴ� ���Դϴ�.K�� �� �ڸ����� �����̰�, Q�� 0�ڸ� �̻��� ���ڿ��Դϴ�.
//���� ���, 53(8)�� ������ ���� ������ ������ �� �ֽ��ϴ�.
//53(8) = 5 + 3(8) = 5 + 888 = 5888
//����� ���ڿ��� �־����� ��, �� ���ڿ��� �ٽ� ������ Ǫ�� ���α׷��� �ۼ��ϼ���.

// category : stack, ���ڿ� 
// Ǯ�� �ð� : 30m
// !������ ���ڰ� �������� �� �ʿ� ���� -> ���̸� ������ָ� �� 

#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string input;
	cin >> input;

	stack<char> stk;
	// ���� Ǭ ���ڿ��� ���� 
	int len = 0;
	for (int i = 0; i < input.size(); i++)
	{
		// )�̸� ��
		// ( �� ���ڸ� put
		if (input[i] != ')') stk.push(input[i]);
		else
		{
			// 1) ��ã��
			// 2) ���� ������ֱ� (������ ���� �ִ� ���� ������)
			// 3) ���� Ǯ���� 
			while (!stk.empty())
			{
				char c = stk.top();
				stk.pop();
				// �� ��ȣ������ break ���� ������ ���� ���ֱ�
				if (c == '(') break;
				else ++len;
			}
			// ������(��������)
			if (!stk.empty())
			{
				char c = stk.top(); stk.pop();
				if (c <= '9' && c >= '0') len = len * (c - '0');
			}
		}
	}

	// ������ ��� 
	while (!stk.empty())
	{
		char c = stk.top(); stk.pop();
		if (c <= '9' && c >= '0') ++len;
	}

	cout << len;
}