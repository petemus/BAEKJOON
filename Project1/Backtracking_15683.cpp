// Backtraking > 감시 (15683번)
// 풀이시간 : > 2 h
// 무한 루프 빠지지 않게 조건 잘 확인

// @@ 2차원 배열과 2차원 포인터는 다르다 

#include <iostream>
using namespace std;

int n, m;
int cells[8][8];
pair<int, int> cctv[8];
int minBlind = 64;
int numCCTV = 0;
//
int cctvDir[8][8] = { 0 };		// cctv 회전 방향 (1:상 2: 하 3: 좌 4:우)


enum Direction
{
	UP = 1,
	DOWN,
	LEFT,
	RIGHT
};

// 함수 전방 선언
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
	// 종료조건 -> cctv를 모두 다 체크했을때
	if (checkCCTV == numCCTV)
	{
		// <사각지대 계산>
		// cctv 찾기
		// 방향별로 cells 업뎃 (복사한 cells에 업뎃)
		// 사각지대 계산
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
	// 상하좌우 넣어주기 
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

	// 입력
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

	// 출력
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
		// 벽이면 탈출
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
