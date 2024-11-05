//  이분 탐색 > 가장 긴 증가하는 부분 수열 2(12015번)

// n 최대 크기 100만 -> O(n^2) 시 시간 초과 => 이분 탐색을 통한 O(nlogn)으로 해결해야함 

#include <iostream>
#include <vector>
#include <algorithm>			// lower_bound() -> 이분 탐색 (시간 복잡도 O(logN)
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// input
	int n;
	cin >> n;

	vector<int> arr(n);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}


	// 이분 탐색을 통한 가장 긴 증가하는 부분 수열 구하기
	// longest increase sequence (LIS)
	vector<int> lis;

	for (int i = 0; i < n; i++)
	{
		// vector<int>::iterator 사용 or auto 사용
		auto neighbor = lower_bound(lis.begin(), lis.end(), arr[i]);
		if (neighbor == lis.end())
		{
			// 찾지 못하면 push
			lis.push_back(arr[i]);
		}
		else
		{
			// 찾으면 해당 위치에 값 변경 
			*neighbor = arr[i];
		}
	}

	// 다음 벡터의 길이가 lis의 길이(크기)
	cout << lis.size();



}