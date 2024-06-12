// Simulation > ����ũ����Ʈ (18111��)
// Ǯ�� �ð� : 45 m 
// sol > ���� ���� �� ~ ���� ������ ��� ��źȭ �۾��� ������ �ּ� ���� �ð��� ���� ���(Brute Force)
// !! ���� ���ٶ� �κ��丮�� �� BLOCK�� �þ�ٴ� ���� �� ����ؾ��� 
// !! �� ���� �۾��� �Ҷ�, ������� ���ʿ� ���� ���� ���̰� ���� ������ ������ �۾��� ������� -> ������������ ����
// !! �ִ�� ���� �� �ִ� �ð��� 5000�� �������� �� ������ �ʿ䰡 ���� 

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, b;
	vector<int> blocks;
	int maxH = 0, minH = 256;
	
	// input
	cin >> n >> m >> b;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int t;
			cin >> t;
			blocks.push_back(t);
			if (t > maxH) maxH = t;
			if (t < minH) minH = t;
		}
	}

	sort(blocks.begin(), blocks.end(), greater<int>());

	int maxHeight = 0, minTime = 50000000;
	// i ���ڷ� ����� 
	for (int i = maxH; i >= minH; i--)
	{
		int time = 0;		
		int haveBlock = b;

		// i���� ũ�� �ٿ��ְ�(������ �� �ٿ��൵ ��)
		// i���� ������ ���̱� -> b ���� Ȯ���ؾ���
		bool isSuccess = true;
		for (int j = 0; j < n * m; j++)
		{
			int gab = abs(blocks[j] - i);
			if (blocks[j] > i)
			{
				// block �߰��������
				haveBlock += gab;
				time += gab * 2;
			}
			else if (blocks[j] < i)
			{
				if (haveBlock >= gab)
				{
					haveBlock -= gab;
					time += gab;
				}
				else
				{
					isSuccess = false;
					break;
				}
			}
		}

		// �ش� ���̷� �� ���� ������ �ּ� �ð� Ȯ��
		if (isSuccess)
		{
			if (time < minTime)
			{
				maxHeight = i;
				minTime = time;
			}
		}

	}


	// output
	cout << minTime << " " << maxHeight;


}