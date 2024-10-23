// 1차원에서의 선분에서 겹치는 부분이 없는 최소 선분 묶음을 구하는 문제
// ! 둘이 겹치면 하나의 긴 선분으로 만들기 가능 
// 그리디, 정렬 or 완탐
// 풀이 시간 : 50m ㅜ

// 1) 값 끝나는 기준으로 정렬 -> Compare함수 정의 필요
// 2) 정렬된 배열에서 하나씩 꺼내가면서 선분 구하기 -> 10만 정도 걸림


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool compare(vector<int> a, vector<int> b)
{
	// 두번째 요소가 큰 순서대로 정렬
	// 두번째 요소 같으면 첫번째 요소가 큰순서대로
	if (a[1] == b[1])
	{
		return a[0] > b[0];
	}
	else return a[1] > b[1];
}


vector<vector<int>> getMergedLineSegments(vector<vector<int>>& lineSegments)
{
	// lineSegments 정렬
	sort(lineSegments.begin(), lineSegments.end(), compare);

	// 결과 배열
	vector<vector<int>> reResults;

	// 전체 돌면서 결과 배열에 넣어줌
	int startPoint = lineSegments[0][0];
	int endPoint = lineSegments[0][1];
	for (int i = 1; i < lineSegments.size(); i++)
	{
		// 다음 끝점이 startpoint보다 큰경우 -> 다음 시작점이랑 startpoint랑 비교
		if (startPoint <= lineSegments[i][1])
		{
			if (startPoint > lineSegments[i][0])
			{
				// startPoint 업데이트
				startPoint = lineSegments[i][0];
			}
			else
			{
				// starpoint보다 크면 넘어가기
				continue;
			}
		}
		else
		{
			// StartPoint보다 작은 경우 -> vector에 값 넣어줌, startpoint, endPoint 업데이트
			vector<int> point = {startPoint, endPoint};
			reResults.push_back(point);
			
			startPoint = lineSegments[i][0];
			endPoint = lineSegments[i][1];
		}
	}
	// 마지막 점도 넣어줘야 함
	vector<int> point = { startPoint, endPoint };
	reResults.push_back(point);

	// 꺼꾸로 반환
	reverse(reResults.begin(), reResults.end());
	return reResults;
	
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	


	vector<vector<int>> lineSegments = {{4, 8}, {2, 6}, {5, 7}};

	vector<vector<int>> results = getMergedLineSegments(lineSegments);

	// 출력
	cout << "{ ";
	for (int i = 0; i < results.size(); i++)
	{
		cout << "[";
		for (int j = 0; j < results[0].size(); j++)
		{
			cout << results[i][j] << " ";
		}
		cout << "] ";
	}
	cout << " }\n";
}


