// Backtracking, ���ǿ� ��ȸ ���� (Traveling Salesman problem : TSP) > ���ǿ� ��ȸ 2 (10971��)
// ���ͽ�Ʈ��� �ڱ� �ڽ����� ���ƿ��� ���� 
// Ǯ�� �ð� : 35m

// n�� ������ 25�� �Ѿ�� ������ Backtracking, ��Ž���� �����ϱ� ��

#include <iostream>
using namespace std;

// ���� ����
int startCitiy = 0;
// ���� ��
int n;
// �ּ� cost
int minCost = 10000000;

int cities[11][11] = {0,};
int isVisited[11] = {false,};


void Backtracking(int citiy, int depth, int sumCost)
{
	// ���� ����
	if (depth == n)
	{
		// ��� ���ø� �� ������ ���
		// �ٽ� ���ư� �� �ִ��� Ȯ��
		if (cities[citiy][startCitiy] > 0)
		{
			// ���ư� �� ������ Ȯ��
			sumCost += cities[citiy][startCitiy];
			if(sumCost < minCost) minCost = sumCost;
		}
		return;
	}

	// �̵��� �� �ִ� �� ã�� -> ��ȸ
	for (int i = 0; i < n; ++i)
	{
		// 0�� �ƴϸ� �̵� ���� 
		// �湮 ������ �湮�ϸ� �ȵ�.
		if (cities[citiy][i] > 0 && !isVisited[i])
		{
			isVisited[i] = true;
			Backtracking(i, depth + 1, sumCost + cities[citiy][i]);
			isVisited[i] = false;
		}
	}

}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// �Է�
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> cities[i][j];
		}
	}

	// ��� ���ÿ��� ���� ��ȸ
	for (int i = 0; i < n; i++)
	{
		startCitiy = i;
		isVisited[i] = true;
		Backtracking(i, 1, 0);
		isVisited[i] = false;
	}
	
	// �ּ� ��� ���
	cout << minCost;


}