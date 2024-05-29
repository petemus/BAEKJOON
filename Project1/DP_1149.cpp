// Dynamic Programing > RGB 거리 (1149번)
// 문제 잘못 읽음 이슈 -> 문제 요약 i 번째와 i-1 번째의 색깔은 달라야 함. or i번쨰와 i + 1번쨰 색깔이 달라야 함

// -------------------------------------------------
// std::min() std::max() : 최소, 최대 구해주는 함수 
// #include <algorithm> / min_element(first, last), max_element(first, last) : first에서 last 까지의 최대 최소 iterator를 반환
// -------------------------------------------------


#include <iostream>
#include <vector>
#include <algorithm>	// min_element(), max_element()  
using namespace std;

enum Color
{
	RED = 0,
	GREEN,
	BLUE
};


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int red[1000];
	int green[1000];
	int blue[1000];

	// 입력
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> red[i] >> green[i] >> blue[i];
	}


	// memo i가 r, g, b일때의 최솟값 저장
	int memo[1000][3];

	memo[0][RED] = red[0]; memo[0][BLUE] = blue[0]; memo[0][GREEN] = green[0];

	for (int i = 1; i < n; i++)
	{
		memo[i][RED] = min(memo[i-1][GREEN], memo[i-1][BLUE]) + red[i];
		memo[i][GREEN] = min(memo[i - 1][RED], memo[i - 1][BLUE]) + green[i];
		memo[i][BLUE] = min(memo[i - 1][GREEN], memo[i - 1][RED]) + blue[i];
	}

	cout << *min_element(memo[n - 1], memo[n - 1] + 3);

}