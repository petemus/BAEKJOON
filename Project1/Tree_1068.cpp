// Tree > 트리(1068번)
// 풀이 시간: 40m

// point 1> 노드 삭제를 어떻게 진행할지 -> 자식 노드를 요소로 가지는 배열과, 부모 노드를 가지는 배열을 이용해서 
//			삭제하면 될듯 -> 실제로 삭제는 부모 노드에서만 지워주면 됨 -> 연결이 끊기므로 
// point 2> 리프 노드를 어떻게 셀지 -> DFS로 자식 없으면 리프 노드 
// !! 항상 index 접근 신중 


#include <iostream>	
#include <vector>
using namespace std;

// index일때 부모 노드
vector<int> parents;
// index일때 자식 노드
vector<vector<int>> childs;
// Root 노드
int root = 0;
// leat 수
int leafCnt = 0;

// DFS
void DFS(int node)
{

	// 자식 없으면 leaf 노드
	if (childs[node].size() == 0)
	{
		++leafCnt;
		return;
	}

	// DFS
	for (int i = 0; i < childs[node].size(); ++i)
	{
		DFS(childs[node][i]);
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// input
	int n;
	cin >> n;

	// 배열 재할당
	parents.resize(n, -1);
	childs.resize(n);
	// *input
	for (int i = 0; i < n; ++i)
	{
		int t;
		cin >> t;

		if (t == -1)
		{
			// 루트 노드
			root = i;
		}
		else
		{
			// 일반 노드
			childs[t].push_back(i);
			parents[i] = t;
		}

	}

	// 노드 삭제
	int dNode;
	cin >> dNode;
	if (dNode == root)
	{
		cout << 0;
		return 0;
	}

	int p = parents[dNode];
	// 찾고 지워주는 시간 복잡도 O(n^2) -> 2500
	for (auto iter = childs[p].begin(); iter != childs[p].end();)
	{
		if (*(iter) == dNode)
		{
			// 지워주기
			iter = childs[p].erase(iter);
		}
		else ++iter;
	}

	// 탐색
	DFS(root);
	// 출력
	cout << leafCnt;

}