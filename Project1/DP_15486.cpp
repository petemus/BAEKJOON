// DP > ���2 (15486��)
// Ǯ�� �ð� : �𸣰ڴ� ������...

// ���� ������ ����� �켱������ �ϰ� �Ǹ� ����� ���� �� �� ���� -> But, pay�� �ֱ⿡ �޶��� �� ���� 
// N�� 150���̿��� ���� ���� ����

// Top-down?


#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;

#define MEMOSIZE 1500001

int n;
// first : Time, second : pay
vector<pair<int,int>> schedul;
int memo[MEMOSIZE];

int DP(int day)
{

	if(memo[day] == -1) return memo[day];






	return memo[day];
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> n;
	schedul.push_back({0, 0});
	for (int i = 0; i < n; i++)
	{
		int t, p;
		cin >> t >> p;
		schedul.push_back({t, p});
	}

	memset(memo, -1, sizeof(int)* MEMOSIZE);

	DP(n);


}

