// Backtraking > ���� (15683��)
// Ǯ�̽ð� : > 2 h
// ���� ���� ������ �ʰ� ���� �� Ȯ��

// @@ 2���� �迭�� 2���� �����ʹ� �ٸ��� 

#include <iostream>
using namespace std;

int n, m;
int cells[8][8];
pair<int, int> cctv[8];
int minBlind = 64;
int numCCTV = 0;
//
int cctvDir[8][8] = { 0 };		// cctv ȸ�� ���� (1:�� 2: �� 3: �� 4:��)


enum Direction
{
	UP = 1,
	DOWN,
	LEFT,
	RIGHT
};

// �Լ� ���� ����
int findBlind(const int cells[][8]);
void drawUp(int cells[][8], int i, int j);
void drawDown(int cells[][8], int i, int j);
void drawLeft(int cells[][8], int i, int j);
void drawRight(int cells[][8], int i, int j);
void drawCCTV1(int cells[][8], int i, int j);
void drawCCTV2(int cells[][8], int i, int j);
void drawCCTV3(int cells[][8], int i, int j);
void drawCCTV4(int cells[][8], int i, int j);
void drawCCTV5(int cells[][8], int i, int j);


void Backtracking(int checkCCTV)
{
	// �������� -> cctv�� ��� �� üũ������
	if (checkCCTV == numCCTV)
	{
		// <�簢���� ���>
		// cctv ã��
		// ���⺰�� cells ���� (������ cells�� ����)
		// �簢���� ���
		int copyCells[8][8];
		copy(&cells[0][0], &cells[0][0] + 64, &copyCells[0][0]);
		for (int i = 0; i < numCCTV; i++)
		{
			int y = cctv[i].first;
			int x = cctv[i].second;
			switch (cells[y][x])
			{
			case 1:
				drawCCTV1(copyCells, y, x);
				break;
			case 2:
				drawCCTV2(copyCells, y, x);
				break;
			case 3:
				drawCCTV3(copyCells, y, x);
				break;
			case 4:
				drawCCTV4(copyCells, y, x);
				break;
			case 5:
				drawCCTV5(copyCells, y, x);
				break;
			default:
				break;
			}
		}

		int blindCell = findBlind(copyCells);
		if (minBlind > blindCell) minBlind = blindCell;
		return;
	}

	//
	int y = cctv[checkCCTV].first;
	int x = cctv[checkCCTV].second;
	// �����¿� �־��ֱ� 
	for (int k = 1; k < 5; k++)
	{
		if (cells[y][x] == 2 && (k == 2 || k == 4)) continue;
		if (cells[y][x] == 5 && k > 1) continue;

		cctvDir[y][x] = k;
		Backtracking(checkCCTV + 1);
		cctvDir[y][x] = 0;
	}

}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// �Է�
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> cells[i][j];
			if (cells[i][j] > 0 && cells[i][j] < 6) cctv[numCCTV++] = { i, j };
		}
	}

	// Backtracking
	Backtracking(0);

	// ���
	cout << minBlind;

}

int findBlind(const int cells[][8])
{
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (cells[i][j] == 0) ++num;
		}
	}
	return num;
}

void drawUp(int cells[][8], int i, int j)
{
	for (int k = i - 1; k >= 0; k--)
	{
		// ���̸� Ż��
		if (cells[k][j] == 6) break;
		if (cells[k][j] == 0) cells[k][j] = 8;
	}
}
void drawDown(int cells[][8], int i, int j)
{
	for (int k = i + 1; k < n; k++)
	{
		if (cells[k][j] == 6) break;
		if (cells[k][j] == 0) cells[k][j] = 8;
	}
}
void drawLeft(int cells[][8], int i, int j)
{
	for (int k = j - 1; k >= 0; k--)
	{
		if (cells[i][k] == 6) break;
		if (cells[i][k] == 0) cells[i][k] = 8;
	}
}
void drawRight(int cells[][8], int i, int j)
{
	for (int k = j + 1; k < m; k++)
	{
		if (cells[i][k] == 6) break;
		if (cells[i][k] == 0) cells[i][k] = 8;
	}
}

void drawCCTV1(int cells[][8], int i, int j)
{
	switch (cctvDir[i][j])
	{
	case UP:
		drawUp(cells, i, j);
		break;
	case DOWN:
		drawDown(cells, i, j);
		break;
	case LEFT:
		drawLeft(cells, i, j);
		break;
	case RIGHT:
		drawRight(cells, i, j);
		break;
	default:
		break;
	}
}

void drawCCTV2(int cells[][8], int i, int j)
{
	switch (cctvDir[i][j])
	{
	case UP:
		drawUp(cells, i, j);
		drawDown(cells, i, j);
		break;
	case LEFT:
		drawLeft(cells, i, j);
		drawRight(cells, i, j);
		break;
	default:
		break;
	}
}

void drawCCTV3(int cells[][8], int i, int j)
{
	switch (cctvDir[i][j])
	{
	case UP:
		drawUp(cells, i, j);
		drawRight(cells, i, j);
		break;
	case DOWN:
		drawLeft(cells, i, j);
		drawDown(cells, i, j);
		break;
	case LEFT:
		drawLeft(cells, i, j);
		drawUp(cells, i, j);
		break;
	case RIGHT:
		drawRight(cells, i, j);
		drawDown(cells, i, j);
		break;
	default:
		break;
	}
}

void drawCCTV4(int cells[][8], int i, int j)
{
	switch (cctvDir[i][j])
	{
	case UP:
		drawUp(cells, i, j);
		drawLeft(cells, i, j);
		drawRight(cells, i, j);
		break;
	case DOWN:
		drawDown(cells, i, j);
		drawLeft(cells, i, j);
		drawRight(cells, i, j);
		break;
	case LEFT:
		drawLeft(cells, i, j);
		drawUp(cells, i, j);
		drawDown(cells, i, j);
		break;
	case RIGHT:
		drawRight(cells, i, j);
		drawUp(cells, i, j);
		drawDown(cells, i, j);
		break;
	default:
		break;
	}
}

void drawCCTV5(int cells[][8], int i, int j)
{
	drawUp(cells, i, j);
	drawDown(cells, i, j);
	drawLeft(cells, i, j);
	drawRight(cells, i, j);
}
