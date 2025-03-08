// ����, ��Ʈ��ŷ  > ��Ʈ�ι̳�(14500��)
// Ǯ�� �ð� : 40 ~ 50m


// point1> 5������ ��Ʈ�ι̳��� ��Ģ�� �� ���� 4���� �̾��� �ִ� ��� ��ΰ� 5���� ��Ʈ�ι̳�� ǥ�� ����
//			-> bfs�� �̾����ִ� �κи� ã�Ƽ� ��Ž�ϸ� ��
// point2> Ž���Ҷ� 4���� �׸��ؾ� �ϹǷ� ��Ͱ� �����ҵ�
// point3> ���� ->  ��, ��, ��, �� ���� ����� �Ϲ������� 4���� Ž���� �� �ٸ�
//			=> ����� ���� �ϳ��Ƿ� �� ��縸 üũ ���� 



#include <iostream>
#include <vector>
using namespace std;


int n, m;
vector<vector<int>> papers;

// ���� �迭 
int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {1, 0, -1, 0};
// �湮 üũ �迭
vector<vector<bool>> isVisited;

// ĭ�� �ִ� ��
int maxSum = 0; 

void Backtracking(int x, int y, int cellNum, int sum)
{
	
	// ���� ���� 
	if (cellNum >= 4)
	{
		// �ִ밪 ��
		if(sum > maxSum) maxSum = sum;
		return;
	}


	// Ž��
	for (int i = 0; i < 4; ++i)
	{
		int nextX, nextY;
		nextX = x + dirX[i];
		nextY = y + dirY[i];

		if(nextX < 0 || nextX >= m || nextY < 0 || nextY >= n) continue;

		if (!isVisited[nextY][nextX])
		{
			// �湮���� �ʾ����� �湮
			isVisited[nextY][nextX] = true;
			Backtracking(nextX, nextY, cellNum + 1, sum + papers[nextY][nextX]);
			isVisited[nextY][nextX] = false;
		}
	}
	

}


void CheckSpecialCase(int x, int y)
{

	for (int i = 0; i < 4; ++i)
	{
		int index = i;
		int sum = papers[y][x];

		for (int j = 0; j < 3; ++j)
		{
			index = (index + j) % 4;
			
			int nY = y + dirY[index];
			int nX = x + dirX[index];

			if(nY < 0 || nY >= n || nX < 0 || nX >= m) break;

			sum += papers[nY][nX];
		}

		if(sum > maxSum) maxSum = sum;

	}
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// *input*
	cin >> n >> m;
	// resize
	papers.resize(n, vector<int>(m, 0));
	isVisited.resize(n, vector<bool>(m, false));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> papers[i][j];
		}
	}


	// ��� ��쿡�� �׷��� Ž�� 
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			// �迭 �� �ʱ�ȭ
			for (int k = 0; k < n; ++k) fill_n(isVisited[k].begin(), m, false);

			// �Ϲ� Ž��
			isVisited[i][j] = true;
			Backtracking(j, i, 1, papers[i][j]);
			// Ư�� ���̽� Ž�� 
			CheckSpecialCase(j, i);
		}
	}


	// Output
	cout << maxSum;


}