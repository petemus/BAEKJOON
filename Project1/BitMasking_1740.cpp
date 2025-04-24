// Bitmasking > 거듭제곱(1740번)
// 풀이 시간 :

// point1> 1, 3, 9, 27.. 등  서로 다른(0,1로 표현 가능-> 비트마스킹) 3의 거듭제곱수의 합으로 표현
// point2> N 의 크기 의미 5000억 -> int 형의 최대 수는 21억이므로 long long 형이여야할듯 
// point3> 구현 > N번째만큼 더해주고 -> 그 값을 3의 거듭제곱으로 변환 

// ! 시간 초과 -> 비트 자리수만큼 해줘야 함
// ! 틀림 -> result의 값이 long long의 범위를 넘어가는 게 아니라 << 연산이 문제
//			!1 << i는 int 범위 (31비트)를 초과하면 오버플러우 발생함

#include <iostream>
#include <cmath>	// pow() -> pow는 double 형 반환 주의 
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	long long n;
	cin >> n;

	// 비트마스킹
	unsigned long long p = 0;

	// N 만큼 비트에 더해주고
	// 그 값을 3의 거듭제곱으로 변환
	p += n;

	long long result = 0;
	long long seq = 1;
	// 비트 자리수만큼 계산 
	for (int i = 0; i < 64; ++i)
	{
		// 비트 값이 있으면 더해줌
		// !! 1 << i는 int 범위 (31비트)를 초과하면 오버플러우 발생함
		// !! pow 사용시 반환값이 double이여서 오류날 수도 있음
		if (p & (1LL << i))
		{
			//result += pow(3, i);
			result += seq;
		}
		seq *= 3;
	}

	cout << result;

}