// DP > 스티커 (9465번)
// 풀이 시간 : 3~40m 

// Point 1 > 서로 변을 공유하지 않는 스티커를 골라야 함 -> 2행 모두 (스티커 뜯기, 안뜯기로 나뉠 수 있음)
//		=> 총 4 * n 배열로 memorization 하면 됨
// Point 2 > [n] = max([n-1]의 1행 , [n-1]의 2행의 x 

#include <iostream>
#include <algorithm>
using namespace std;

int stickers[2][1000002];
int sMemo[2][1000002];
int nMemo[2][1000002];


int main()
{  
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n;
	cin >> t;


	while (t--)
	{
		// input
		cin >> n;
		for (int i = 0; i < 2; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> stickers[i][j];
			}
		}
		
		sMemo[0][0] = stickers[0][0];
		sMemo[1][0] = stickers[1][0];
		nMemo[0][0] = 0;
		nMemo[1][0] = 0;

		// DP 
		for (int i = 1; i < n; ++i)
		{
			sMemo[0][i] = max(sMemo[1][i - 1], nMemo[0][i - 1]) + stickers[0][i];
			sMemo[1][i] = max(sMemo[0][i - 1], nMemo[1][i - 1]) + stickers[1][i];

			// 전체 안해도 테케는 다 통과하긴 함..
			nMemo[0][i] = max({sMemo[1][i - 1], sMemo[0][i - 1], nMemo[0][i - 1], nMemo[1][i - 1]});
			nMemo[1][i] = nMemo[0][i];
		}

		// output
		cout << max({ sMemo[1][n - 1], sMemo[0][n - 1], nMemo[0][n - 1], nMemo[1][n - 1] }) << '\n';
	}


}