//목표량
//시간 제한 : 1초
//엘리스 토끼는 목표량을 정해 수학 문제를 열심히 풉니다.목표량은 정수입니다.
//내일 풀 수학 문제의 개수는 오늘 푼 문제 개수의 수와 숫자의 구성이 같으면서, 오늘 푼 문제 개수의 수보다 큰 수 중 가장 작은 수입니다.
//예를 들어, 오늘 67문제를 풀었으면 다음 날 76문제를 풉니다.
//오늘 푼 문제의 개수를 줬을 때 다음날 풀 문제의 개수를 출력하는 프로그램을 작성하세요

// category : BruteForce 
// 풀이 시간 : 30m

// @@
// #include <string> : stoi() : string -> integer
// #include <string> : to_string() : integer -> string 



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string input;
	cin >> input;
	int n = stoi(input);

	// nums의 최대 개수 6개
	vector<int> nums;
	for (int i = 0; i < input.size(); i++)
	{
		int num = input[i] - '0';
		nums.push_back(num);
	}

	// 작은 수부터 만들기 위해 정렬
	sort(nums.begin(), nums.end());
	
	int result = 0;
	// BruteForce 
	for (int i = 1; i <= 999999; i++)
	{
		// 입력값보다 큰지 확인
		// 오늘 푼 문제 개수와 수의 구성이 같은지 확인 
		result = i;
		if (result > n)
		{
			vector<int> arr;
			string s = to_string(result);
			for (int j = 0; j < s.size(); j++)
			{
				arr.push_back(s[j] - '0');
			}
			sort(arr.begin(), arr.end());
			// arr와 nums가 같은지 확인
			if (arr == nums) break;
		}
	}

	cout << result;
}