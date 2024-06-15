// DP > 평범한 배낭(12865번) -> 실패 
// 풀이 시간 :
//

// 1) Backtracking  -> 시간 초과
// 2) DP -> 아직 이해가 안됨

#include <iostream>
#include <vector>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	int object[100][2];

	// Input
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> object[i][0] >> object[i][1];
	}

	// DP



	// Output


	// Backtracking
	//Backtracking(0, 0, 0);
	//cout << maxValue;
}

// ------------ Backtracking

//int n, k;
//int object[100][2];		//  물건 w, v 저장
//// 물건 가지고 있는지
//bool isHave[100] = { false, };
//int maxValue = 0;
//
//void Backtracking(int thingCnt, int allWeight, int allValue)
//{
//	
//	// object 넣어주기 
//	for (int i = 0; i < n; i++)
//	{
//		// 가지고 있지 않으면 백트랙킹
//		if (!isHave[i] && (allWeight + object[i][0]) <= k)
//		{
//			isHave[i] = true;
//			Backtracking(thingCnt + 1, allWeight + object[i][0], allValue + object[i][1]);
//			isHave[i] = false;
//		}
//	}
//
//	// 종료 조건
//	// > 더이상 넣을 object 가 없을 때
//	// 최대 가치합인지 확인
//	if (allValue > maxValue) maxValue = allValue;
//	return;
//
//}