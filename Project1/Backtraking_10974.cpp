// Backtraking > ��� ���� (10974)
// endl�� ������ ������ �˰��� ���� Ǯ���� �� ���� �� ���� ��

#include <iostream>
#include <vector>

using namespace std;


int n;
int path[8];
bool isVisited[9] = { false, };


void Backtracking(int depth)
{
	// ���� ����
	if (depth == n)
	{
		// ���
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
		// �湮���� �ʾ����� �湮
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