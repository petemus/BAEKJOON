// Brute Force > �밨�� ��� ���� (14718��)
// Ǯ�� �ð� : 1h 10m
// ��� : ��� BruteForce�� ���� �� ���ؾ��� 

// k���� ������ ������ �ִ��� ���� ���� �ּ� ���� ����Ʈ 
// Brtue Force -> 100 * 100 * 100 ��ŭ ���� 100�� => power, speed. intel ���� ������ �������� Ȯ��
// Backtracking => �ð� �ʰ�

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	
	// ���� ���ʿ俩�� vector�� �� ���� �ʿ� ���� 
	vector<int> pow;
	vector<int> speed;
	vector<int> intel;
	int enemy[100][3];
	for (int i = 0; i < n; i++)
	{
		int p, s, k;
		cin >> p >> s >> k;
		pow.push_back(p); speed.push_back(s); intel.push_back(k);
		enemy[i][0] = p; enemy[i][1] = s; enemy[i][2] = k;
	}
	// ������������ ���� -> ������ ��ü Ž���̿��� ���� ���ʿ� ����
	sort(pow.begin(), pow.end());
	sort(speed.begin(), speed.end());
	sort(intel.begin(), intel.end());

	int jPow = 0, jSpeed = 0, jIntel = 0;
	int minStateSum = 3000000;
	for (int i = 0; i < n; i++)
	{
		jPow = pow[i];
		for (int j = 0; j < n; j++)
		{
			jSpeed = speed[j];
			for (int m = 0; m < n; m++)
			{
				jIntel = intel[m];
				int win = 0;
				for (int l = 0; l < n; l++)
				{
					if (jPow >= enemy[l][0] && jSpeed >= enemy[l][1] && jIntel >= enemy[l][2]) ++win;
				}
				if (win >= k)
				{
					int stateSum = jPow + jSpeed + jIntel;
					if (stateSum < minStateSum) minStateSum = stateSum;
				}
			}
		}
	}

	cout << minStateSum;
}