// 문자열, 구현  > 그룹 단어 체커 (1316번)
// 풀이 시간 : 20m

// 단어가 한번에 모여 있어야 함 
// 이전 알파벳과(prevWorld)와 현재 알파벳과 비교햄
// 이미 나옴 알파벳이 또나왔는데 이전 알파벳과 다르면 -> 그룹단어가 아님


#include <iostream>
#include <unordered_set>
using namespace std;


bool CheckGroupWord(string word)
{

	// 중복 체크는 일반 배열(26개), set 모두 사용 가능
	unordered_set<char> usedAlpha;
	char prevDigit = 'a' - 1;

	for (int i = 0; i < word.size(); ++i)
	{
		char nowDigit = word[i];

		if (nowDigit <= 'z' && nowDigit >= 'a')
		{
			// 이전 digit이 있으면 현재랑 비교 
			//	같으면 -> pass
			//	다르면 -> set에 있는지 확인 
				// 있으면 -> gw 아님
				// 없으면 -> set에 insert
			if (nowDigit != prevDigit)
			{
				if (usedAlpha.find(nowDigit) != usedAlpha.end())
				{
					// set에 있으면
					return false;
				}
			}
		}

		usedAlpha.insert(nowDigit);
		prevDigit = nowDigit;
	}

	// 통과하면 gw
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
			// 참이면 gwCnt 증가
			++gwCnt;
		}

	}

	cout << gwCnt;



}