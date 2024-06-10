// Simulation > 뱀 (3190번)
// 풀이 시간 : 1 h 
// 꼬리가 어떻게 이동하는지가 핵심인듯 -> board에 이동 방향 표시 

#include <iostream> 
using namespace std;

char board[100][100] = {};
char change[10001] = { };
// index : 위 = 0, 오른 = 1, 아래 = 2, 왼 = 3
int dirX[] = {0, 1, 0, -1};
int dirY[] = {-1, 0, 1, 0};

struct Pos
{
	int x;
	int y;
	Pos(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	Pos() {};
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 입력
	int n, k, l;
	cin >> n >> k;
	fill_n(&board[0][0], 100 * 100, '.');
	fill_n(change, 10001, '0');
	for (int i = 0; i < k; i++)
	{
		int r, c;
		cin >> r >> c;
		board[r - 1][c - 1] = 'A';
	}
	cin >> l;
	for (int i = 0; i < l; i++)
	{
		int sec;
		char dir;
		cin >> sec >> dir;
		change[sec] = dir;
	}

	// 구현 
	int playTime = 0;
	int snakeDir = 1;	// 지렁이 오른쪽으로 향함
	Pos tailPos = Pos(0, 0);
	Pos headPos = Pos(0, 0);
	board[headPos.y][headPos.x] = snakeDir + '0';

	bool isGameOver = false;
	while (!isGameOver)
	{
		// 시간 경과
		// 뱀 몸 늘림 + 벽 부딪히는지(몸이랑 부딪히는지) 확인
		// 이동 후 사과 유무 확인
		++playTime;
		int nextX = headPos.x + dirX[snakeDir];
		int nextY = headPos.y + dirY[snakeDir];
		if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < n)
		{
			if ((board[nextY][nextX] - '0') >= 0 && (board[nextY][nextX] - '0') < 4)
			{
				// 몸통과 부딪히면 오버
				isGameOver = true;
				continue;
			}
			else
			{
				if (board[nextY][nextX] != 'A')
				{
					// 사과 아닐때만 꼬리길이 줄여줌
					int tailDir = board[tailPos.y][tailPos.x] - '0';
					board[tailPos.y][tailPos.x] = '.';
					tailPos.x = tailPos.x + dirX[tailDir];
					tailPos.y = tailPos.y + dirY[tailDir];
				}
				//headPos = Pos(nextX, nextY);
				headPos.x = nextX;
				headPos.y = nextY;
				
			}
		}
		else
		{
			isGameOver = true;
			continue;
		}


		// 방향 바뀌는지 확인
		if (change[playTime] == 'L')
		{
			// 왼쪽으로 90도 회전 -> -1 
			snakeDir = (snakeDir + 3) % 4;
		}
		else if (change[playTime] == 'D')
		{
			// 오른쪽 90도 회전 -> +1 
			snakeDir = (snakeDir + 1) % 4;
		}

		// 방향 넣어줌
		board[headPos.y][headPos.x] = snakeDir + '0';

	}

	cout << playTime;

}