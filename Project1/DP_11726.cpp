// DP > 2*N 타일링 (11726번)


#include <iostream>
#include <memory.h>
using namespace std;


// [i] = [i - 1] + [i -2]
// 한칸 늘어나면 할 수 있는 경우 가 세로로 한개 세우는 것과 가로로 2개 세우는 것
// 세로로 한 개는 [i -1]에 한 개를 세우는 경우니까 [i-1]의 개수와 같고
// 가로로 2개 세우는 거는 [i-2]에 가로 2개 세우는 것과 같아서 [i-2]와 같음 

// ! 10007을 나눈다는 것이 핵심 -> memo의 값이 매우 커진다는 뜻 
// modulo 연산 -> 합 분해 ( (A+B) mod c == (A mod c + B mod C) mod c (뺄셈 분해, 곱 분해 마찬가지)

// index개일때 직사각형 체우는 수
long long memo[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int n;
	cin >> n;

	memset(memo, -1, 1001  * sizeof(long long));

	// 초기값
	memo[1] = 1; memo[2] = 2;

	// Bottom-Up
	for (int i = 3; i <= n; i++)
	{
		memo[i] = (memo[i -1] + memo[i - 2]) % 10007;
	}

	cout << memo[n] % 10007;

}