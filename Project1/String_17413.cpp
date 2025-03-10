// 구현, 문자열 > 단어 뒤집기 2 (17413번)
// 풀이 시간 : 20m

// ! 그냥 하나씩 입력 받고 경우의 수 다 해주면 되는데
// -> 조금 더 깔끔하게 풀 방법이 있을듯 


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
			// 그 이전에 단어가 있으면 출력
			if (!isSubStr)
			{
				// 단어 거꾸로 출력
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

			// 부분 문자열
			isSubStr = true;
			word += s[i];
			break;
		}
		case '>':
		{
			isSubStr = false;
			word += s[i];
			// 출력
			cout << word;
			// 초기화
			word = "";
			break;
		}
		case ' ':
		{
			if (!isSubStr)
			{
				// 단어 거꾸로 출력
				for (int k = word.size()-1; k >= 0; --k)
				{
					cout << word[k];
				}
				cout << ' ';
				// 초기화
				word = "";
			}
			else
			{
				// 추가
				word += s[i];
			}
			break;
		}
		default:
		{
			// 소문자, 숫자 
			word += s[i];
			break;
		}

		}
	}
	

	// 마지막 출력 
	if (!isSubStr)
	{
		// 단어 거꾸로 출력
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