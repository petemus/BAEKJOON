// Simulation(구현) > 주사위 굴리기(14499번)
// 풀이 시간 :  1h 20m 정도... (구현하는 것도 쉽지 않음)

// Point 1 > 1->5로 가는 거랑 3->5로 가는거랑 방향이 다름 => 주사위 굴릴때마다 방향 업뎃 


#include <iostream>
using namespace std;

// 동서남북 정의
#define TOP 0
#define EAST 1
#define WEST 2
#define NORTH 3
#define SOUTH 4

// map 크기
int n, m;
// 주사위 1~6까지의 4방향 위치 (0: 주사위 상단, 1: 동 2: 서 3: 북 4: 남)
int DiceDir[7][5];
// 주사위 쓰여있는 값 (초기값 0)
int Dice[7] = {0, };
// 지도
int map[20][20];
// 방향에 따른 이동 배열 (동서북남)
int dirX[4] = {1, -1, 0, 0};
int dirY[4] = {0, 0, -1, 1};


void UpdateDiceDir(int now, int move, int dir)
{
	// dir에 따라 move의 DiceDir 값이 바뀜 
	// 동서는 now의 북남이 같음, 북남은 now의 동서가 같음 
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

	//주사위 초기값 세팅
	DiceDir[1][TOP] = 6;
	DiceDir[1][EAST] = 3; DiceDir[1][WEST] = 4; DiceDir[1][NORTH] = 2; DiceDir[1][SOUTH] = 5;
	//현재 밑에 있는 주사위 수
	int down = 1;

	//*이동 수행
	while (k--)
	{
		int dir;
		cin >> dir;

		// x, y에서 dir를 통해 이동 가능한지 체크 
		int moveX = x + dirX[dir - 1];
		int moveY = y + dirY[dir - 1];
		if(moveX < 0 || moveX >= m || moveY < 0 || moveY >= n) continue;

		// x, y 값 업뎃
		x = moveX;
		y = moveY;

		// 이동할 주사위 DiceDir 업뎃
		int move = DiceDir[down][dir];
		UpdateDiceDir(down, move, dir);
		// 주사위 이동 
		down = DiceDir[down][dir];
		
		// map 값 업뎃
		if (map[y][x] == 0)
		{
			// 주사위 바닥면 값을 칸에 복사
			map[y][x] = Dice[down];
		}
		else
		{
			// 칸에 쓰여있는 값이 주사위 바닥면에 복사 + 칸은 0이 됨
			Dice[down] = map[y][x];
			map[y][x] = 0;
		}

		// 이동했으면 윗면에 있는 수 출력
		cout << Dice[DiceDir[down][0]] << '\n';

	}

}