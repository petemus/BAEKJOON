// Simulation(����) > �ֻ��� ������(14499��)
// Ǯ�� �ð� :  1h 20m ����... (�����ϴ� �͵� ���� ����)

// Point 1 > 1->5�� ���� �Ŷ� 3->5�� ���°Ŷ� ������ �ٸ� => �ֻ��� ���������� ���� ���� 


#include <iostream>
using namespace std;

// �������� ����
#define TOP 0
#define EAST 1
#define WEST 2
#define NORTH 3
#define SOUTH 4

// map ũ��
int n, m;
// �ֻ��� 1~6������ 4���� ��ġ (0: �ֻ��� ���, 1: �� 2: �� 3: �� 4: ��)
int DiceDir[7][5];
// �ֻ��� �����ִ� �� (�ʱⰪ 0)
int Dice[7] = {0, };
// ����
int map[20][20];
// ���⿡ ���� �̵� �迭 (�����ϳ�)
int dirX[4] = {1, -1, 0, 0};
int dirY[4] = {0, 0, -1, 1};


void UpdateDiceDir(int now, int move, int dir)
{
	// dir�� ���� move�� DiceDir ���� �ٲ� 
	// ������ now�� �ϳ��� ����, �ϳ��� now�� ������ ���� 
	switch (dir)
	{
	case EAST:
	DiceDir[move][NORTH] = DiceDir[now][NORTH]; DiceDir[move][SOUTH] = DiceDir[now][SOUTH];
	DiceDir[move][WEST] = now; DiceDir[move][EAST] = DiceDir[now][TOP]; DiceDir[move][TOP] = DiceDir[now][WEST];
	break;
	case WEST:
	DiceDir[move][NORTH] = DiceDir[now][NORTH]; DiceDir[move][SOUTH] = DiceDir[now][SOUTH];
	DiceDir[move][WEST] = DiceDir[now][TOP]; DiceDir[move][EAST] = now; DiceDir[move][TOP] = DiceDir[now][EAST];
	break;
	case NORTH:
	DiceDir[move][WEST] = DiceDir[now][WEST]; DiceDir[move][EAST] = DiceDir[now][EAST];
	DiceDir[move][NORTH] = DiceDir[now][TOP]; DiceDir[move][SOUTH] = now; DiceDir[move][TOP] = DiceDir[now][SOUTH];
	break;
	case SOUTH:
	DiceDir[move][WEST] = DiceDir[now][WEST]; DiceDir[move][EAST] = DiceDir[now][EAST];
	DiceDir[move][NORTH] = now; DiceDir[move][SOUTH] = DiceDir[now][TOP]; DiceDir[move][TOP] = DiceDir[now][NORTH];
	break;
	default:
		break;
	}
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	//*input
	cin >> n >> m;

	int x, y, k;
	cin >> y >> x >> k;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> map[i][j];
		}
	}

	//�ֻ��� �ʱⰪ ����
	DiceDir[1][TOP] = 6;
	DiceDir[1][EAST] = 3; DiceDir[1][WEST] = 4; DiceDir[1][NORTH] = 2; DiceDir[1][SOUTH] = 5;
	//���� �ؿ� �ִ� �ֻ��� ��
	int down = 1;

	//*�̵� ����
	while (k--)
	{
		int dir;
		cin >> dir;

		// x, y���� dir�� ���� �̵� �������� üũ 
		int moveX = x + dirX[dir - 1];
		int moveY = y + dirY[dir - 1];
		if(moveX < 0 || moveX >= m || moveY < 0 || moveY >= n) continue;

		// x, y �� ����
		x = moveX;
		y = moveY;

		// �̵��� �ֻ��� DiceDir ����
		int move = DiceDir[down][dir];
		UpdateDiceDir(down, move, dir);
		// �ֻ��� �̵� 
		down = DiceDir[down][dir];
		
		// map �� ����
		if (map[y][x] == 0)
		{
			// �ֻ��� �ٴڸ� ���� ĭ�� ����
			map[y][x] = Dice[down];
		}
		else
		{
			// ĭ�� �����ִ� ���� �ֻ��� �ٴڸ鿡 ���� + ĭ�� 0�� ��
			Dice[down] = map[y][x];
			map[y][x] = 0;
		}

		// �̵������� ���鿡 �ִ� �� ���
		cout << Dice[DiceDir[down][0]] << '\n';

	}

}