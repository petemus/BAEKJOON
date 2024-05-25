// Recursion > 큰 수 구성하기 (18511번)


#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


vector<int> num;
int n, k;
int mmax = 0;


void Recur(int digit, int now)
{

	if (n < now) return;
	int res = n / pow(10, digit);
	if (res == 0)
	{
		if (mmax < now) mmax = now;
		return;
	}

	if (mmax < now) mmax = now;

	for (int i = 0; i < k; i++)
	{
		Recur(digit + 1, now + (num[i] * pow(10, digit)));
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	int tmp;
	for (int i = 0; i < k; i++)
	{
		cin >> tmp;
		num.push_back(tmp);
	}


	Recur(0, 0);

	cout << mmax;


}