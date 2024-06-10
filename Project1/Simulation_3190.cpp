// Simulation > �� (3190��)
// Ǯ�� �ð� : 1 h 
// ������ ��� �̵��ϴ����� �ٽ��ε� -> board�� �̵� ���� ǥ�� 

#include <iostream> 
using namespace std;

char board[100][100] = {};
char change[10001] = { };
// index : �� = 0, ���� = 1, �Ʒ� = 2, �� = 3
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

	// �Է�
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

	// ���� 
	int playTime = 0;
	int snakeDir = 1;	// ������ ���������� ����
	Pos tailPos = Pos(0, 0);
	Pos headPos = Pos(0, 0);
	board[headPos.y][headPos.x] = snakeDir + '0';

	bool isGameOver = false;
	while (!isGameOver)
	{
		// �ð� ���
		// �� �� �ø� + �� �ε�������(���̶� �ε�������) Ȯ��
		// �̵� �� ��� ���� Ȯ��
		++playTime;
		int nextX = headPos.x + dirX[snakeDir];
		int nextY = headPos.y + dirY[snakeDir];
		if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < n)
		{
			if ((board[nextY][nextX] - '0') >= 0 && (board[nextY][nextX] - '0') < 4)
			{
				// ����� �ε����� ����
				isGameOver = true;
				continue;
			}
			else
			{
				if (board[nextY][nextX] != 'A')
				{
					// ��� �ƴҶ��� �������� �ٿ���
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


		// ���� �ٲ���� Ȯ��
		if (change[playTime] == 'L')
		{
			// �������� 90�� ȸ�� -> -1 
			snakeDir = (snakeDir + 3) % 4;
		}
		else if (change[playTime] == 'D')
		{
			// ������ 90�� ȸ�� -> +1 
			snakeDir = (snakeDir + 1) % 4;
		}

		// ���� �־���
		board[headPos.y][headPos.x] = snakeDir + '0';

	}

	cout << playTime;

}