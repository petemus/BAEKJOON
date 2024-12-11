// BitMasking, 수학  > 막대기 (1094번)

// 1 : 01
// 2 : 10
// 4 : 100
// 8 : 1000
// 16: 10000
// 32: 100000
// 64: 1000000
// x 값은 1,.. 64의 숫자로 조합하여 만들 수 있음 -> ex) 32 + 8 + 2 = 42
// ! 다음 값은 중복될 수 없음
// 실제로 x값의 이진값은 각 자리수의 조합으로 되어 있음 -> 각 자리 수가 있을때  더하면 됨 


#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x;
	cin >> x;

	// 64 자리까지 비교해줌
	int cnt = 0;
	for (int i = 0; i < 8; ++i)
	{
		if (x & (1 << i))
		{
			// 자리 수있으면 체크
			++cnt;
		}
	}

	cout << cnt;


}