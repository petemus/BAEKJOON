// Backtracking, 브루트 포스 > 리모콘(1107)
// (1) Backtracking > 자리수 대로 백트랙킹
// 1. 자리 수가 넘어가는 경우는 포함 못함 -> 한자리수만 추가
// 2. 00100 자리수대로 push를 하면 오류 발생 -> 나중에 제거해줘도
// (2) 브루트 포스 > 걍 숫자 단위로 backtracking


#include <iostream>
#include <math.h>
#include <string>
using namespace std;

bool breakNum[10] = { false, };
int minPush;
int now = 100;

bool isPossible(int num)
{
	string s = to_string(num);

	bool isPossible = true;
	for (int i = 0; i < s.size(); i++)
	{
		if (breakNum[s[i] - '0']) isPossible = false;
	}

	return isPossible;
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{9
		int tmp; 
		cin >> tmp;
		breakNum[tmp] = true;
	}

	// bruteForce 
	minPush = abs(n - now);

	for (int i = 0; i < 1000000; i++)
	{
		if (isPossible(i))
		{
			// push 수 계산 해줌
			// 1) 버튼 누른 수
			// 2) 움직인 수
			int push = to_string(i).size();
			push += abs(n - i);
			// 최소값 비교
			if (minPush > push) minPush = push;
		}
	}

	// 출력
	cout << minPush;

}