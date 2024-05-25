// Backtracking > 알파벳 (1987번)
// 풀이 시간 : 30 min

#include <iostream>

using namespace std;

char board[20][20];
int r, c;
int maxCell = 0;
// 중복된 문자인지 확인 
// 인덱스로 문자 아스키 정수값 들어옴 -> 실제로 쓰이는 인덱스 범위 65 ~ 90
// ** 인덱스에  'A'를 빼주면 0번 인덱스부터 사용 가능 
bool alpha[100] = { false, };

// direct 배열  (상하좌우)
int dirX[] = { 0, 0, -1, 1 };
int dirY[] = { -1, 1, 0, 0 };

void Backtracking(int nowX, int nowY, int move)
{
	// 종료 조건 -> 이동할 곳이 없으면 종료 

	alpha[board[nowY][nowX]] = true;

	// Backtracking
	// 이동할 수 있는지 없는지 체크
	bool isMove = false;
	for (int i= 0; i < 4; i++)
	{
		int nextX, nextY;
		nextX = nowX + dirX[i];
		nextY = nowY + dirY[i];
		// next 인덱스 이동 범위 잘 체크
		if (nextX >= 0 && nextX < c && nextY >= 0 && nextY < r)
		{
			// 중복된 문자인지 확인
			if (!alpha[board[nextY][nextX]])
			{
				Backtracking(nextX, nextY, move + 1);
				// 나오면 이동한 거 체크 해제
				alpha[board[nextY][nextX]] = false;
				isMove = true;
			}
		}

	}

	// 종료 조건
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

	// 입력
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
	
	// 출력
	cout << maxCell;

}