// Tree > Ʈ��(1068��)
// Ǯ�� �ð�: 40m

// point 1> ��� ������ ��� �������� -> �ڽ� ��带 ��ҷ� ������ �迭��, �θ� ��带 ������ �迭�� �̿��ؼ� 
//			�����ϸ� �ɵ� -> ������ ������ �θ� ��忡���� �����ָ� �� -> ������ ����Ƿ� 
// point 2> ���� ��带 ��� ���� -> DFS�� �ڽ� ������ ���� ��� 
// !! �׻� index ���� ���� 


#include <iostream>	
#include <vector>
using namespace std;

// index�϶� �θ� ���
vector<int> parents;
// index�϶� �ڽ� ���
vector<vector<int>> childs;
// Root ���
int root = 0;
// leat ��
int leafCnt = 0;

// DFS
void DFS(int node)
{

	// �ڽ� ������ leaf ���
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

	// �迭 ���Ҵ�
	parents.resize(n, -1);
	childs.resize(n);
	// *input
	for (int i = 0; i < n; ++i)
	{
		int t;
		cin >> t;

		if (t == -1)
		{
			// ��Ʈ ���
			root = i;
		}
		else
		{
			// �Ϲ� ���
			childs[t].push_back(i);
			parents[i] = t;
		}

	}

	// ��� ����
	int dNode;
	cin >> dNode;
	if (dNode == root)
	{
		cout << 0;
		return 0;
	}

	int p = parents[dNode];
	// ã�� �����ִ� �ð� ���⵵ O(n^2) -> 2500
	for (auto iter = childs[p].begin(); iter != childs[p].end();)
	{
		if (*(iter) == dNode)
		{
			// �����ֱ�
			iter = childs[p].erase(iter);
		}
		else ++iter;
	}

	// Ž��
	DFS(root);
	// ���
	cout << leafCnt;

}