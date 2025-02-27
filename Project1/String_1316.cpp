// ���ڿ�, ����  > �׷� �ܾ� üĿ (1316��)
// Ǯ�� �ð� : 20m

// �ܾ �ѹ��� �� �־�� �� 
// ���� ���ĺ���(prevWorld)�� ���� ���ĺ��� ����
// �̹� ���� ���ĺ��� �ǳ��Դµ� ���� ���ĺ��� �ٸ��� -> �׷�ܾ �ƴ�


#include <iostream>
#include <unordered_set>
using namespace std;


bool CheckGroupWord(string word)
{

	// �ߺ� üũ�� �Ϲ� �迭(26��), set ��� ��� ����
	unordered_set<char> usedAlpha;
	char prevDigit = 'a' - 1;

	for (int i = 0; i < word.size(); ++i)
	{
		char nowDigit = word[i];

		if (nowDigit <= 'z' && nowDigit >= 'a')
		{
			// ���� digit�� ������ ����� �� 
			//	������ -> pass
			//	�ٸ��� -> set�� �ִ��� Ȯ�� 
				// ������ -> gw �ƴ�
				// ������ -> set�� insert
			if (nowDigit != prevDigit)
			{
				if (usedAlpha.find(nowDigit) != usedAlpha.end())
				{
					// set�� ������
					return false;
				}
			}
		}

		usedAlpha.insert(nowDigit);
		prevDigit = nowDigit;
	}

	// ����ϸ� gw
	return true;
}


int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int gwCnt = 0;
	while (n--)
	{
		string word;
		cin >> word;

		if (CheckGroupWord(word))
		{
			// ���̸� gwCnt ����
			++gwCnt;
		}

	}

	cout << gwCnt;



}