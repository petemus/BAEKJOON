// Backtracking > ���ĺ� (1987��)
// Ǯ�� �ð� : 30 min

#include <iostream>

using namespace std;

char board[20][20];
int r, c;
int maxCell = 0;
// �ߺ��� �������� Ȯ�� 
// �ε����� ���� �ƽ�Ű ������ ���� -> ������ ���̴� �ε��� ���� 65 ~ 90
// ** �ε�����  'A'�� ���ָ� 0�� �ε������� ��� ���� 
bool alpha[100] = { false, };

// direct �迭  (�����¿�)
int dirX[] = { 0, 0, -1, 1 };
int dirY[] = { -1, 1, 0, 0 };

void Backtracking(int nowX, int nowY, int move)
{
	// ���� ���� -> �̵��� ���� ������ ���� 

	alpha[board[nowY][nowX]] = true;

	// Backtracking
	// �̵��� �� �ִ��� ������ üũ
	bool isMove = false;
	for (int i= 0; i < 4; i++)
	{
		int nextX, nextY;
		nextX = nowX + dirX[i];
		nextY = nowY + dirY[i];
		// next �ε��� �̵� ���� �� üũ
		if (nextX >= 0 && nextX < c && nextY >= 0 && nextY < r)
		{
			// �ߺ��� �������� Ȯ��
			if (!alpha[board[nextY][nextX]])
			{
				Backtracking(nextX, nextY, move + 1);
				// ������ �̵��� �� üũ ����
				alpha[board[nextY][nextX]] = false;
				isMove = true;
			}
		}

	}

	// ���� ����
	if (!isMove)
	{
		if (move > maxCell) maxCell = move;
		return;
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// �Է�
	cin >> r >> c;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> board[i][j];
		}
	}

	// Backtracking
	Backtracking(0, 0, 1);
	
	// ���
	cout << maxCell;

}