// ����, ���ڿ� > �ܾ� ������ 2 (17413��)
// Ǯ�� �ð� : 20m

// ! �׳� �ϳ��� �Է� �ް� ����� �� �� ���ָ� �Ǵµ�
// -> ���� �� ����ϰ� Ǯ ����� ������ 


#include <iostream>
#include <string>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	getline(cin, s);

	string word = "";
	bool isSubStr = false;

	for (int i = 0; i < s.size(); ++i)
	{
		switch (s[i])
		{

		case '<':
		{
			// �� ������ �ܾ ������ ���
			if (!isSubStr)
			{
				// �ܾ� �Ųٷ� ���
				for (int k = word.size() - 1; k >= 0; --k)
				{
					cout << word[k];
				}
			}
			else
			{
				cout << word;
			}
			word = "";

			// �κ� ���ڿ�
			isSubStr = true;
			word += s[i];
			break;
		}
		case '>':
		{
			isSubStr = false;
			word += s[i];
			// ���
			cout << word;
			// �ʱ�ȭ
			word = "";
			break;
		}
		case ' ':
		{
			if (!isSubStr)
			{
				// �ܾ� �Ųٷ� ���
				for (int k = word.size()-1; k >= 0; --k)
				{
					cout << word[k];
				}
				cout << ' ';
				// �ʱ�ȭ
				word = "";
			}
			else
			{
				// �߰�
				word += s[i];
			}
			break;
		}
		default:
		{
			// �ҹ���, ���� 
			word += s[i];
			break;
		}

		}
	}
	

	// ������ ��� 
	if (!isSubStr)
	{
		// �ܾ� �Ųٷ� ���
		for (int k = word.size() - 1; k >= 0; --k)
		{
			cout << word[k];
		}
	}
	else
	{
		cout << word;
	}

}