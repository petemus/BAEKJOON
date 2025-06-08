// DP, BFS > ���� ���� (11060��)
// Ǯ�� �ð� : 40m -> ���� �߻��� �� �ִ� �Ÿ� ã�°� ���� �ɸ�...

// !���� ������ ������ �� �� ���� ��� -1 ���
// !�������� ���� ĭ�� 0�� �̵��� ��������� ��


// ����!!) �������� ���ߴµ� ���� �Ǵ��� �� �� ����....

// Ǯ�� 2) BFS(�ּ� ����̹Ƿ� ����)
// �ּ� ��θ� ã�°ŹǷ� ����
// maximun 100 * 1000 = 10���̹Ƿ� �����ҵ�


#include <iostream>	
#include <algorithm>	// min, max 
#include <cstring> // memset
using namespace std;

// �ּ� ���� ���� ����Ǵ� �迭
int memo[1001];
// �̷� �迭
int maze[1001];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// input
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> maze[i];
	}

	// dp
	// �ʱ�ȭ, size : ũ�� * ����Ʈ
	memset(memo, -1, sizeof(maze));
	memo[0] = 0;
	for (int i = 0; i < n; ++i)
	{
		// @@@@ �湮���� ���� ���̸� pass �ؾ���
		if(memo[i] < 0) continue;

		for (int j = 1; j <= maze[i]; ++j)
		{
			// �迭 ũ�� üũ
			if(i + j >= n) break;

			// �湮������ �ּҰ� ��
			if (memo[i + j] >= 0)
				memo[i + j] = min(memo[i + j], memo[i] + 1);
			else 
				// �湮 �������� �ٷ� �� �־��� 
				memo[i + j] = memo[i] + 1;
		}
	}


	// output
	if(memo[n - 1] == 0 && n != 1) cout << -1;
	else cout << memo[n - 1];


}