// dp > 이친수 (2193번)
// 이친수 개수
// 1일때 다은 수가 1이면 안되는 문제 

// !규칙 찾기 -> 맨 마지막 글자가 0이면 다음에 나올 수 있는 수 1, 0
// -> 마지막이 1이면 다음 글자는 무조건 0
// => 마지막이 0인 이친수 수, 마지막이 1인 이친수 수
// =>  0[i] = 0[i-1] + 1[i-1] :: 1[i] = 0[i-1]
// ! 이전 값들이 계속 더해진다 -> 지수 형식으로 매우 커진다.


#include <iostream>
#include <memory.h>
using namespace std;

// ! 이전 값들이 계속 더해진다 -> 지수 형식으로 매우 커진다.

// index 번째 수가 0인 이친수 수
long long memo0[91];
// index 번째 수가 1인 이친수 수
long long memo1[91];



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	memset(memo0, -1, 91 * sizeof(int));
	memset(memo1, -1, 91 * sizeof(int));


	// 초기값
	memo0[1] = 0;
	memo1[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		// 식의 범위
		memo0[i] = memo0[i - 1] + memo1[i - 1];
		memo1[i] = memo0[i - 1];
 	}

	// 전체는 둘 다 합
	cout << memo0[n] + memo1[n];

	
}