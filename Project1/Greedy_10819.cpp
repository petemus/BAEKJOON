// 완탐, 백트랙킹, 그리디?(그리디 아닌가?)  > 차이를 최대로 (10819번)
// 풀이 시간 : 


// 임의 순서 i 번째에서 i-1, i+1 번째의 수의 차 값이 최대를 구해야함 
// n이 8이여서 (최대 8! -> 4만 정도해서 완탐 가능할듯)


// 그리디 ->  정렬 후 가장 먼 애들끼리가 차이가 최대임 


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	vector<int> arr;

	// input
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		arr.push_back(num);
	}

	// 정렬
	sort(arr.begin(), arr.end());

	// 제일 먼 곳부터 뺴기

	int left = 0;
	int right = n -1;

	// 최댓값
	int difSum = arr[right] - arr[left];

	while (left < right)
	{
		if (left + 1 == right - 1)
		{
			// 홀수이면, 둘 차이가 큰 애로 선택
			difSum += (arr[right] - arr[right -1]) > (arr[left + 1] - arr[left]) ?
			arr[right] - arr[right - 1] : arr[left + 1] - arr[left];
		}
		else
		{
			// 아니면 값 더해주기 
			difSum += arr[right - 1] - arr[left];
			difSum += arr[right] - arr[left + 1];
		}

		++left;
		--right;
	}

	cout << difSum;


}