// DP > ���2 (15486��)
// Ǯ�� �ð� : @, �ùķ��̼� �ϱ� ���� ����...

// ���� ������ ����� �켱������ �ϰ� �Ǹ� ����� ���� �� �� ���� -> But, pay�� �ֱ⿡ �޶��� �� ���� 
// N�� 150���̿��� ���� ���� ���� -> �켱 ���� ť...?

// Top-down?


#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;

#define MEMOSIZE 1500001


int n;
// first : EndDay, second : cost
vector<pair<int,int>> schedul;
// index ��¥�϶� �ִ� �ݾ�
int memo[MEMOSIZE];



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> n;

	schedul.push_back({0,0});
	for (int i = 1; i <= n; i++)
	{
		int t, p;
		cin >> t >> p;
		schedul.push_back({i + t - 1, p});
	}

	memset(memo, 0, sizeof(int)* MEMOSIZE);

	// i������ �ִ밪
	int M = 0;
	for (int i = 1; i <= n; i++)
	{

		// ���� ��¥������ �ִ밪�� ���ؼ� �־��ֱ�
		memo[i] = max(M, memo[i]);

		// EndDay�� i���� �۰ų� ������ ���� ������ �ִ� ���� ���Ͽ� �ֱ�
		int iEndDay = schedul[i].first;
		if (iEndDay == i)
		{
			// ���� �� ������ �Ÿ�(�ڱ� ��¥ ���� �ȵǾ� �����ϱ�) �����ְ�
			// ���� �ִ� ���̸�(�ڱ� ��¥ ����) M���ٰ� ���� ������ ������
			if (M == memo[i]) memo[i] += schedul[i].second;
			else memo[i] = max(M + schedul[i].second, memo[i]);
		}
		else if(iEndDay < MEMOSIZE)
		{
			// EndDay�� ũ�� �� ��¥�� ���� ���ؼ� �־���
			// �̶��� memo�� �ִ� ���� �ڱ��ڽ��� �����ߴ��� ��
			memo[iEndDay] = max(memo[iEndDay], M + schedul[i].second);
		}

		// M ����
		M = max(M, memo[i]);
	}

	cout << memo[n];


	//DP(n);


}

