// Tree, BFS, DFS > 트리의 부모 찾기 (11725번)
// 풀이 시간 : 12 40 

// point 1> 누가 부모인지 모름 -> 일단 다 연결해 놓음 -> 1부터 시작해서 방문 체크를 하면서 Backtracking 
//		!주위 > 노드 찾을때마다 Backtracking 해주면 암됨 -> DFS로 전체 저장후 나중에 출력 BFS 가능 But pair로 해줘야함 
//		? 최악일 경우 10만 * 10만 이 나오지 않을까? => 아님 간선의 수는 n-1, 부모 자식 중복해서 들어가니까 2(n-1)개임

#include <iostream>
#include <vector>	
#include <queue>
using namespace std;

// 노드 수
int n;
// 각 노드들의 연결되어 있는 것들 
vector<vector<int>> node;
// 노드의 부모 저장 
vector<int> childParent;

// BFS
// 모든 자식의 부모 노드 넣어줌 
void BFS()
{
	
	vector<bool> isVisited(n + 2, false);
	queue<int> q;

	//초기값
	q.push(1);
	isVisited[1] = true;

	while (!q.empty())
	{
		int parent = q.front();
		q.pop();

		for (int i = 0; i < node[parent].size(); ++i)
		{
			//방문하지 않은 모든 자식 탐색
			int child = node[parent][i];
			if (!isVisited[child])
			{
				childParent[child] = parent;
				q.push(child);
				isVisited[child] = true;
			}
		}
	}

}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// input
	cin >> n;
	
	node.resize(n + 2);
	childParent.resize(n + 2);

	for (int i = 0; i < n - 1; ++i)
	{
		int a, b;
		cin >> a >> b;
		// 둘 노드에 넣어주기 
		node[a].push_back(b);
		node[b].push_back(a);
	}

	// BFS로 모든 노드의 부모 찾아주기
	BFS();

	// 2번 노드부터 순차적으로 출력
	for (int i = 2; i <= n; ++i)
	{
		cout << childParent[i] << '\n';
	}

}