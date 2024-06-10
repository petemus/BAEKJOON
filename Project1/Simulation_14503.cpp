// Simulation > �κ� û�ұ� (14503��)
// Ǯ�� �ð� : 40 m
// �ּ� �̷� ���� ã�� �� �ƴ϶� �� �����ϴ� ����

#include <iostream>
using namespace std;

int n, m;
char cells[50][50] = { 0, };
// index = 0 ��, ��, ��, ��
int dirX[] = { 0, 1, 0, -1 };
int dirY[] = { -1, 0, 1, 0 };

// r, c�� �� ���� �߿� ������ ���� �ִ���(û���� �� �ִ���) Ȯ��
bool isDirty(int r, int c)
{
	for (int i = 0; i < 4; i++)
	{
		int nowX, nowY;
		nowX = c + dirX[i];
		nowY = r + dirY[i];
		if (nowX >= 0 && nowX < m && nowY >= 0 && nowY < n)
		{
			if (cells[nowY][nowX] == '0') return true;
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	int robotR, robotC, robotD;
	cin >> robotR >> robotC >> robotD;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> cells[i][j];
		}
	}


	// �۵��� ���⶧���� �ݺ�
	// ���� ĭ û�ҵ��� ������ û��
	// ��ĭ ������ ->
	// ������ -> 
	bool isShoutdown = false;

	int cleanCells = 0;
	while (!isShoutdown)
	{	
		// ���� ĭ û�� ���� ������ û��
		if (cells[robotR][robotC] == '0') {
			cells[robotR][robotC] = '.';
			cleanCells++;
		}

		int nextX, nextY;
		if (isDirty(robotR, robotC))
		{
			// ��ĭ ������
			// �ݽð�� 90�� ȸ��
			// ���� ĭ�� 0�̸� ����
			if (robotD == 0) robotD = 3;
			else robotD -= 1;
			nextX = robotC + dirX[robotD];
			nextY = robotR + dirY[robotD];
			// ������ �� �ִ��� index üũ
			if(nextX >= 0 && nextX < m && nextY >= 0 && nextY < n)
			{
				if (cells[nextY][nextX] == '0')
				{
					robotC = nextX;
					robotR = nextY;
				}
			}
		}
		else
		{
			// ��ĭ ������ �ٶ󺸴� ������ ������ä ����
			// ������ ���� dir���� + 2 �� ���� % 4
			int backDir = (robotD + 2) % 4;
			nextX = robotC + dirX[backDir];
			nextY = robotR + dirY[backDir];
			if (nextX >= 0 && nextX < m && nextY >= 0 && nextY < n)
			{
				// ���� �����ϸ� ��
				if (cells[nextY][nextX] != '1')
				{
					robotC = nextX;
					robotR = nextY;
				}
				else isShoutdown = true;
			}
		}
	}

	cout << cleanCells;

}