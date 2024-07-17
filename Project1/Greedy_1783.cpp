// Greedy > 병든 나이트 (1783번)

// 방문한 칸의 수 최대 
// 4번 보다 크면 4가지 방법 모두 한번씩 사용 

// 보드 N * M
// 나이트 위치 : (n -1, 0)

// 1) + (-2, +1)
// 2) + (-1, +2)
// 3) + (+1, +2)
// 4) + (+2, +1)

// ! 무조건 +1 or +2이고 -> 만나는 경우가 있을 수 없음 => 그리디 


#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	
	int result = 0;

	if (n >= 3 && m >= 7) result = m - 2;
	else if (n >= 3 && m < 7)
	{
		if (m >= 5) result = 4;
		else if (m < 5)  result = m;
	}
	else if (n == 2)
	{
		if (m <= 8) result = (m + 1) / 2;
		else result = 4;
	}
	else if (n == 1) result = 1;

	cout << result;
}