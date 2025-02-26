// 완탐, 백트랙킹, hash > 카드 놓기 (5568번)
// 풀이 시간 : 30m


// point 1> 수 만들기 -> 완탐, 백트래킹으로 가능
// point 2> 중복 체크 -> 변수의 크기가 작아서 완탐 가능, (set, map) 사용 
// point 3> 숫자를 어떻게 카드처럼 이용? => 문자열 이용 (문자열로 받아서 더하는 식으로)


#include <iostream>
#include <unordered_set>
using namespace std;


int numCnt = 0;
int n, k;

string cards[11];
bool isUsed[11] = {false,};
unordered_set<string> uset;


void Backracking(string c, int cnt)
{
	if (cnt >= k)
	{
		// 해당 문자열이 있는지 체크
		if (uset.find(c) == uset.end())
		{
			// 없으면 set에 넣기
			uset.insert(c);
			++numCnt;
		}
		return;
	}

	// Backtracking
	for (int i = 0; i < n; ++i)
	{
		if (!isUsed[i])
		{
			// 방문 안했으면 Backtracking
			isUsed[i] = true;
			Backracking(c + cards[i], cnt + 1);
			isUsed[i] = false;
		}
	}


}


int main()
{
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// input
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		cards[i] = s;
	}


	// Backtracking
	Backracking("", 0);

	cout << numCnt;

}