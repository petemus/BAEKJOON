// 그리디 > 한 줄로 서기(1138번)
// 풀이 시간 : 40m


// 왼쪽에 자기보다 큰 사람의 수만 암 
// point1> 자기 앞자리 수로부터 내 위치 알 수 있음 
// point2> 나보다 작은 수의 위치와 나의 최소위치와 비교해가면서 내 자리 찾기 



#include <iostream>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// input
	int n;
	cin >> n;

	// 줄을 선 순서대로 키
	int line[12] = {0, };
	int leftTall[12];

	for (int i = 0; i < n; ++i)
	{
		cin >> leftTall[i];
	}


	// 키 작은 놈부터 순서대로 line 배정
	for (int i = 0; i < n; ++i)
	{
		// 최소 위치 -> 왼쪽에 큰 사람들 수 (leftTall)
		// 최대 위치 -> 왼쪽에 큰 사람들 수 + 자기보다 작은 사람 수 (Max 크기 체크)
		// int minIdx = leftTall[i];
		// int maxIdx = ((leftTall[i] + i) < (n-1)) ? leftTall[i] + i : n - 1;

		int nowIdx = leftTall[i];

		// 모든 라인체크해서 minIdx 또는 maxIdx 기준으로 계산
		for (int j = 0; j < n; ++j)
		{
			if (line[j] > 0)
			{
				// 값이 있으면 minIdx와 비교
				if(j <= nowIdx)
				{
					++nowIdx;
				}
			}
		}

		// 위치 찾으면 그곳에 값 넣어줌
		line[nowIdx] = i + 1;
	}




	// output
	for (int i = 0; i < n; ++i)
	{
		cout << line[i] << ' ';
	}




}