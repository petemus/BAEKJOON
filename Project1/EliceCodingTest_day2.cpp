//정리 정돈을 좋아하는 k씨
//시간 제한 : 1초
//정리 정돈을 좋아하는 k씨의 본명은 아무도 모릅니다.사람들은 k씨의 특이한 행동 2가지 때문에 그를 '정리 정돈을 좋아하는 k씨'라고 부릅니다.그 두 가지 행동은 그가 숫자를 정리하는 일을 하면 아무 규칙없이 나열되어 있는 숫자중 범위를 정한 후 무조건 오름차순으로 정리한다는 것, 그리고 오름차순으로 정리된 숫자 중 k번째 숫자를 선택한다는 것입니다
//예를 들어 a = { 1,7,6,8,1,6,4,5 }라는 수열이 있습니다.정리정돈을 좋아하는 k씨는 범위를 2에서 5로 정하고, k를 2라고 정했습니다.
//그러면 ka = { 7,6,8,1 }이 되고, 이것을 오름차순으로 정리를 하면 
// ka = { 1,6,7,8 }이 됩니다.그리고 k씨는 2번째인 6을 선택합니다.
//배열 a가 주어지고, k씨가 일을 한 횟수가 주어졌을 때, k씨가 고른 숫자를 출력하는 프로그램을 작성하세요.

// 풀이 시간 : 20m

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;

	// base가 될 arr 만들기
	vector<int> arr;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		arr.push_back(t);
	}

	// m만큼 반복
	while (m--)
	{
		int i, j, k;
		cin >> i >> j >> k;
		
		vector<int> ka;
		for (int l = i - 1; l < j; l++)
		{
			ka.push_back(arr[l]);
		}
		sort(ka.begin(), ka.end());

		// 출력
		cout << ka[k - 1] << '\n';

	}

}