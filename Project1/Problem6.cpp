// 삼형제의 카드 놀이
// # 투 포인터 
// 3형제가 낸 카드의 합이 t를 넘어가면 안되는 듯
// 1) for문 3개 사용 -> 시간 초과
// 2) Backtracking -> 마찬가지로 시간 초과 날듯
// ! 중복된 값은 사용할 수 없음 
// ! 문제 자체는  간단한듯
// ! 중복 제거 + 큰 수부터 가지 치기 해서 시작
// => 투 포인터 문제인듯 
// 풀이 시간 : 30m

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;


//long three_numbers(int t, vector<int>& d)
//{
//	// vector, 정렬, 
//	sort(d.begin(), d.end());
//	// 중복 제거 
//	d.erase(unique(d.begin(), d.end()), d.end());
//
//	int count = 0;
//	for (int i = d.size() - 1; i >= 2; i--)
//	{
//		int sum = d[i];
//		if(sum > t) continue;
//
//		for (int j = i - 1; j >= 1; j--)
//		{
//			sum += d[j];
//			if (sum > t)
//			{
//				sum -= d[j];
//				continue;
//			}
//
//			for (int k = j - 1; k >= 0; k--)
//			{
//				sum += d[k];
//				if (sum > t)
//				{
//					sum -= d[k];
//					continue;
//				}
//				else count++;
//
//				// back
//				sum -= d[k];
//			}
//
//			// back
//			sum -= d[j];
//		}
//	}
//	return count;
//}

long three_numbers(int t, vector<int>& d) {

	// 중복 제거 및 정렬
	sort(d.begin(), d.end());
	d.erase(unique(d.begin(), d.end()), d.end());

	long count = 0;

	// 첫 번째 수를 고정하고, 나머지 두 수를 투 포인터로 찾음
	for (int i = 0; i < d.size() - 2; ++i) {
		int target = t - d[i];
		int left = i + 1;
		int right = d.size() - 1;

		while (left < right) {
			int sum = d[left] + d[right];
			if (sum <= target) {
				// 가능한 모든 조합의 개수를 추가
				count += (right - left);
				++left;
			}
			else {
				--right;
			}
		}
	}

	return count;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t = 8;
	vector<int> d = {1, 2, 3, 4, 5};


	cout << three_numbers(t, d);

}