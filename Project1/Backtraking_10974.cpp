// Backtraking > 모든 순열 (10974)
// endl은 느리기 때문에 알고리즘 문제 풀때는 안 쓰는 게 좋을 듯

#include <iostream>
#include <vector>

using namespace std;


int n;
int path[8];
bool isVisited[9] = { false, };


void Backtracking(int depth)
{
	// 종료 조건
	if (depth == n)
	{
		// 출력
		for (int i = 0; i < n; i++)
		{
			cout << path[i] << " ";
		}
		cout << "\n";
		return;
	}

	//
	for (int i = 1; i <= n; i++)
	{
		// 방문하지 않았으면 방문
		if (!isVisited[i])
		{
			isVisited[i] = true;
			path[depth] = i;
			Backtracking(depth + 1);
			isVisited[i] = false;
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	Backtracking(0);

}