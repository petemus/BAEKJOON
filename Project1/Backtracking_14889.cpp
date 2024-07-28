// Backtracking > ��ŸƮ�� ��ũ(14889��)
// Ǯ�� �ð� : 7 13


// checkpoint
// 1> �ð� �ʰ� -> ��� ��� ������ �׷��� n�� ���ݸ� Ŀ������ ���� ���� �ſ� Ŀ�� => ����
//	sol1> Backtracking �ݺ����� 1�������Ͱ� �ƴ϶� ���� ���� ������ ���� ���� ������ ����  
//  sol2> �ݺ��Ǵ��� �Ź� �Լ� ȣ���� ���ؼ� üũ���ִ� ���� �ƴ϶� isVisited ���� ������ ���ؼ� üũ���ִ� �� �� �ð� ȿ���� ����


#include <iostream>
using namespace std;

int n;
int ability[21][21] = { 0, };

int minGap = 100000;
int teamA[11] = { 0, };		// team�� index�� ��

bool isTeamA(int num)
{
	// team �迭�� �ִ��� Ȯ�����ִ� �Լ�
	bool isFind = false;
	for (int i = 1; i <= n; i++)
	{
		if (teamA[i] == num) isFind = true;
	}

	return isFind;
}

void Backtraking(int teamNum)
{
	// ���� ����
	if (teamNum == n / 2)
	{
		int teamASum = 0, teamBSum = 0;
		// 0~n-1 �ε����� ����� Ȯ��
		for (int i = 1; i <= n; i++)
		{
			// ���� ���� �ִ� ����鸸 ���
			for (int j = i + 1; j <= n; j++)
			{
				if (isTeamA(i) && isTeamA(j))
				{
					// ���� �� Ȯ��
					teamASum += ability[i][j];
					teamASum += ability[j][i];
				}
				else if (!isTeamA(i) && !isTeamA(j))
				{
					teamBSum += ability[i][j];
					teamBSum += ability[j][i];
				}
			}
		}
		// �ּ����� Ȯ��
		if (abs(teamASum - teamBSum) < minGap) minGap = abs(teamASum - teamBSum);
		return;
	}

	// isVisited ���� ���� �ǰ� isTeam ����ص� �ǰ� 
	for (int i = 1 + teamA[teamNum]; i <= n; i++)
	{
		if (!isTeamA(i))
		{
			// ���� �ҼӵǾ� ���� ������ backtracking
			teamA[teamNum + 1] = i;
			Backtraking(teamNum + 1);
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
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> ability[i][j];
		}
	}


	// Backtracking
	// > �ο� ����
	// > �� �����ϰ� �ɷ�ġ ���� ���
	Backtraking(0);

	// ���
	cout << minGap;
}