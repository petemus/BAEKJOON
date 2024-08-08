// Brute Force > 셀프 넘버(4673번)

#include <iostream>
using namespace std;

int constructNum(int n)
{
	int result = n;
	do
	{
		result += n % 10;
		n = n / 10;
	} while (n != 0);

	return result;
}

bool isSelfNum(int n)
{
	for (int i = 1; i <= n; i++)
	{
		// i가 n의 생성자인지 확인
		if (constructNum(i) == n) return false;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 10^4이고 이중 for문이니까 10^8 = 1000만 => 1초 안에 가능
	int n = 10000;

	// 만 다 체크
	for (int i = 1; i <= n; i++)
	{
		if (isSelfNum(i)) cout << i << '\n';
	}

}