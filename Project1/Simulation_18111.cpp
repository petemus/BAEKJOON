// Simulation > 마인크래프트 (18111번)
// 풀이 시간 : 45 m 
// sol > 가장 높은 땅 ~ 낮은 땅으로 모두 평탄화 작업을 했을때 최소 높이 시간인 것을 출력(Brute Force)
// !! 땅을 없앨때 인벤토리에 들어가 BLOCK이 늘어난다는 것을 잘 고려해야함 
// !! 땅 고르기 작업을 할때, 순서대로 할필요 없음 따라서 높이가 높은 순으로 땅고르기 작업을 해줘야함 -> 내림차순으로 정렬
// !! 최대로 나올 수 있는 시간이 5000만 정도여서 잘 설정할 필요가 있음 

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
	// i 숫자로 만들기 
	for (int i = maxH; i >= minH; i--)
	{
		int time = 0;		
		int haveBlock = b;

		// i보다 크면 줄여주고(실제로 안 줄여줘도 됨)
		// i보다 작으면 높이기 -> b 갯수 확인해야함
		bool isSuccess = true;
		for (int j = 0; j < n * m; j++)
		{
			int gab = abs(blocks[j] - i);
			if (blocks[j] > i)
			{
				// block 추가해줘야함
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

		// 해당 높이로 땅 고르기 성공시 최소 시간 확인
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