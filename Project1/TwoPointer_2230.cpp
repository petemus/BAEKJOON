// 투 포인터 > 수 고르기 (2230번)
// 가장 작게 나는 차이를 구한다 
// ! O(n^2) 시: 시간 초과
//	차이가 가장 작아야함 -> 정렬을 한 상태로 앞 뒤로부터 줄여가면서 가장 작은 차이 구하기

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	// 정렬
	sort(arr.begin(), arr.end());

	// 둘 다 같은 위치에서 시작해서 차이가 적은 거를 찾아 나감
	int start = 0, end = 1;

	// 20억이 최대
	int min = 2000000000;
	while (start < end && end < n)
	{
		int dis = arr[end] - arr[start];
		
		if (dis < m)
		{
			// m보다 작으면 end를 증가
			++end;
		}
		else
		{
			// m보다 크거나 같으면 start를 증가 
			// 이때 최소값인지 확인
			if(dis < min) min = dis;

			// !!! 이게 중요 
			// 근데 만약 start가 증가했을때 end와 같으면 end를 증가 
			if(end - start == 1) ++end;
			else ++start;
		}

	}

	cout << min;



}