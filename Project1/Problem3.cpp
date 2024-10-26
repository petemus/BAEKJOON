// 3> �̴� īƮ���̴�
// # DP
// �̰͵� DP���� -> 1������ ��� 2������ ���
// Ǯ�� �ð�: 1�ð�... �����ϴµ� �������� ���� �ɸ�
// > �ִ밪 �ּҰ��϶� ����Ǵ� ���� ���������� �߿�


#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

#define MAXINDEX 100001
// ���� 1���� �̵��Ѵٰ� �����ϸ� �ִ� 10��
#define MAXMOVE 200000

// 1������ ��� 2������ ��� 3������ ��� ������ ����
// [����][�ε���(�ð�?)] = �ּ� �̵� Ƚ��
int memo[3][MAXINDEX];


int minimumMovement(vector<int>& obstacles)
{

	// memo �ʱⰪ ���� -> ���� ��ġ 2�� ����
	memo[1][0] = 0; 
	memo[2][0] = MAXMOVE; memo[0][0] = MAXMOVE;

	int n = obstacles.size();

	for (int i = 1; i <= obstacles.size(); i++)
	{

		memo[0][i] = MAXMOVE;
		memo[1][i] = MAXMOVE;
		memo[2][i] = MAXMOVE;
		 

		if (memo[0][i - 1] < MAXMOVE)
		{	
			// ��ֹ� �ִ� ���� �ƴϸ� ����
			if(obstacles[i - 1] != 1) memo[0][i] = min(memo[0][i - 1], memo[0][i]);
			if(obstacles[i - 1] != 2) memo[1][i] = min(memo[0][i - 1] + 1, memo[1][i]);
			if(obstacles[i - 1] != 3) memo[2][i] = min(memo[0][i - 1] + 1, memo[2][i]);
		}
		if (memo[1][i - 1] < MAXMOVE)
		{
			if(obstacles[i - 1] != 1) memo[0][i] = min(memo[1][i - 1] + 1, memo[0][i]);
			if(obstacles[i - 1] != 2) memo[1][i] = min(memo[1][i - 1], memo[1][i]);
			if(obstacles[i - 1] != 3) memo[2][i] = min(memo[1][i - 1] + 1, memo[2][i]);
		}
		if (memo[2][i - 1] < MAXMOVE)
		{
			if(obstacles[i - 1] != 1) memo[0][i] = min(memo[2][i - 1] + 1, memo[0][i]);
			if(obstacles[i - 1] != 2) memo[1][i] = min(memo[2][i - 1] + 1, memo[1][i]);
			if(obstacles[i - 1] != 3) memo[2][i] = min(memo[2][i - 1], memo[2][i]);
		}
	}

	return min({memo[0][n], memo[1][n], memo[2][n]});
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> obstacles = {3, 2, 3, 1, 2, 2};


	cout << minimumMovement(obstacles);

}
