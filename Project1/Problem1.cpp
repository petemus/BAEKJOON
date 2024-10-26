// 최대 점수 뽑기 문제
// 쉬운 DP 문제
// #DP , But 일반 구현으로도 풀 수 있음

#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

#define MAX_INDEX 100001

// memo 최대 10만 
int memo0[MAX_INDEX];		// 자기 자신 미포함 memo
int memo1[MAX_INDEX];		// 자기 자신 포함 memo

int GetMaxScore(vector<int>& array)
{

	// memo 초기값
	memo0[0] = 0;
	memo1[0] = array[0];

	// 
	for (int i = 1; i < array.size(); i++)
	{	
		// 자기 미포함이면 이전 index에서는 포함해야함
		memo0[i] = memo1[i - 1];
		// 자기 자신 포함
		memo1[i] = max(memo0[i - 1], memo1[i - 1]) + array[i];
	}

	return max(memo0[array.size() - 1], memo1[array.size() - 1]);

}


int main()
{

	vector<int> array = {-3, 2, 4, -1, -2, -5};

	cout << GetMaxScore(array);

}