// Simulation > 1.감시(15683번)
// 1번 감시 카메라 -> 4방향 이동 가능
// 2번 -> 2방향 이동 가능
// 3번 -> 4방향
// 4번 -> 4방향
// 5번 -> 이동 못함

// 1) 모든 감시 카메라 방향 돌려보면서 최솟값 출력 -> 시간이 오래걸릴 것 같음
// 2) 전체탐색을 하면서 cctv 만나면 방향 돌리면서 최솟값 저장 -> 예외가 있을 듯 => 실패ㄴ

// 방향만 저장하고 마지막에 계산해주는 게 중요

#include <iostream>
#include <vector>
using namespace std;

int n, m; // n이 세로 (행) m이 가로 (열)
int office[8][8];


void cctv1(int y, int x) {
	int max = 0;

	// 4방향으로 검사
	int dirY[] = { 0, 0, 1, -1};
	int dirX[] = { 1, -1, 0, 0 };
	

	// 4방향 중에 가장 적은 곳 -1으로 바꾸기
	int tmpX, tmpY;
	int tmp = 0;
	int mdir = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j < 8; j++) {
			tmpX = x + (dirX[i] * j);
			tmpY = y + (dirY[i] * j);
			// 벽을 마주치거나 넘어가면 break
			if (tmpX < 0 || tmpX >= m || tmpY < 0 || tmpY >= n || office[tmpY][tmpX] == 6) break;
			if (office[tmpY][tmpX] == 0) tmp++;
		}
		// max 검사
		// 크면 값 씌어주기
		if (max < tmp) {
			max = tmp;
			mdir = i;
		}
		tmp = 0;
	}

	// 값 씌어주기
	for (int j = 1; j < 8; j++) {
		tmpX = x + (dirX[mdir] * j);
		tmpY = y + (dirY[mdir] * j);
		// 벽을 마주치거나 넘어가면 break
		if (tmpX < 0 || tmpX >= m || tmpY < 0 || tmpY >= n || office[tmpY][tmpX] == 6) break;
		if (office[tmpY][tmpX] == 0) office[tmpY][tmpX] = -1;
	}
}

void cctv2(int y, int x) {
	int max = 0;

	// 4방향으로 검사
	int dirY[] = { 1, 0 };
	int dirX[] = { 0, 1 };


	// 2방향 중에 가장 적은 곳 -1으로 바꾸기
	int tmpX, tmpY;
	int tmp = 0;
	int mdir = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 1; j < 8; j++) {
			tmpX = x + (dirX[i] * j);
			tmpY = y + (dirY[i] * j);
			// 벽을 마주치거나 넘어가면 break
			if (tmpX < 0 || tmpX >= m || tmpY < 0 || tmpY >= n || office[tmpY][tmpX] == 6) break;
			if (office[tmpY][tmpX] == 0) tmp++;
		}
		for (int j = 1; j < 8; j++) {
			tmpX = x - (dirX[i] * j);
			tmpY = y - (dirY[i] * j);
			// 벽을 마주치거나 넘어가면 break
			if (tmpX < 0 || tmpX >= m || tmpY < 0 || tmpY >= n || office[tmpY][tmpX] == 6) break;
			if (office[tmpY][tmpX] == 0) tmp++;
		}
		// max 검사
		// 크면 값 씌어주기
		if (max < tmp) {
			max = tmp;
			mdir = i;
		}
		tmp = 0;
	}

	// 값 씌어주기
	for (int j = 1; j < 8; j++) {
		tmpX = x + (dirX[mdir] * j);
		tmpY = y + (dirY[mdir] * j);;
		// 벽을 마주치거나 넘어가면 break
		if (tmpX < 0 || tmpX >= m || tmpY < 0 || tmpY >= n || office[tmpY][tmpX] == 6) break;
		if (office[tmpY][tmpX] == 0) office[tmpY][tmpX] = -1;
	}
	for (int j = 1; j < 8; j++) {
		tmpX = x - (dirX[mdir] * j);
		tmpY = y - (dirY[mdir] * j);;
		// 벽을 마주치거나 넘어가면 break
		if (tmpX < 0 || tmpX >= m || tmpY < 0 || tmpY >= n || office[tmpY][tmpX] == 6) break;
		if (office[tmpY][tmpX] == 0) office[tmpY][tmpX] = -1;
	}
}



void cctv3(int y, int x) {
	
	int max = 0;
	// 4방향으로 검사
	int dirY[] = { -1, 1, 1, -1 };
	int dirX[] = { 1, 1, -1, -1 };


	// 4방향 중에 가장 적은 곳 -1으로 바꾸기
	int tmpX, tmpY;
	int tmp = 0;
	int mdir = 0;
	for (int i = 0; i < 4; i++) {
		// x 방향
		for (int j = 1; j < 8; j++) {
			tmpX = x + (dirX[i] * j);
			tmpY = y;
			// 벽을 마주치거나 넘어가면 break
			if (tmpX < 0 || tmpX >= m || tmpY < 0 || tmpY >= n || office[tmpY][tmpX] == 6) break;
			if (office[tmpY][tmpX] == 0) tmp++;
		}
		// y 방향
		for (int j = 1; j < 8; j++) {
			tmpX = x;
			tmpY = y + (dirY[i] * j);
			// 벽을 마주치거나 넘어가면 break
			if (tmpX < 0 || tmpX >= m || tmpY < 0 || tmpY >= n || office[tmpY][tmpX] == 6) break;
			if (office[tmpY][tmpX] == 0) tmp++;
		}
		// max 검사
		// 크면 값 씌어주기
		if (max < tmp) {
			max = tmp;
			mdir = i;
		}
		tmp = 0;
	}

	// 값 씌어주기
	for (int j = 1; j < 8; j++) {
		tmpX = x + (dirX[mdir] * j);
		tmpY = y;
		// 벽을 마주치거나 넘어가면 break
		if (tmpX < 0 || tmpX >= m || tmpY < 0 || tmpY >= n || office[tmpY][tmpX] == 6) break;
		if (office[tmpY][tmpX] == 0) office[tmpY][tmpX] = -1;
	}
	for (int j = 1; j < 8; j++) {
		tmpX = x;
		tmpY = y + (dirY[mdir] * j);
		// 벽을 마주치거나 넘어가면 break
		if (tmpX < 0 || tmpX >= m || tmpY < 0 || tmpY >= n || office[tmpY][tmpX] == 6) break;
		if (office[tmpY][tmpX] == 0) office[tmpY][tmpX] = -1;
	}
}

void cctv4(int y, int x) {
	int max = 0;

	// 4방향으로 검사
	int dirY[] = { -1, 1, 0, 0 };
	int dirX[] = { 0, 0, -1, 1 };

	int tmpX, tmpY;
	int mdir = 0;
	int tmp = 0;
	for (int k = 0; k < 4; k++) {
		for (int i = 0; i < 3; i++) {
			for (int j = 1; j < 8; j++) {
				tmpX = x + (j * dirX[(k + i) % 4]);
				tmpY = y + (j * dirY[(k + i) % 4]);
				if (tmpX < 0 || tmpX >= m || tmpY < 0 || tmpY >= n || office[tmpY][tmpX] == 6) break;
				if (office[tmpY][tmpX] == 0) tmp++;
			}
		}

		if (max < tmp) {
			max = tmp;
			mdir = k;
		}
		tmp = 0;
	}
	

	// 값 씌어주기
	for (int i = 0; i < 3; i++) {
		for (int j = 1; j < 8; j++) {
			tmpX = x + (j * dirX[(mdir + i) % 4]);
			tmpY = y + (j * dirY[(mdir + i) % 4]);
			if (tmpX < 0 || tmpX >= m || tmpY < 0 || tmpY >= n || office[tmpY][tmpX] == 6) break;
			if (office[tmpY][tmpX] == 0) office[tmpY][tmpX] = -1;
		}
	}
}

void cctv5(int y, int x) {

	int dirY[] = { -1, 1, 0, 0 };
	int dirX[] = { 0, 0, -1, 1 };
	int tmpX, tmpY;
	
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j < 8; j++) {
			tmpX = x + (j * dirX[i]);
			tmpY = y + (j * dirY[i]);
			if (tmpX < 0 || tmpX >= m || tmpY < 0 || tmpY >= n || office[tmpY][tmpX] == 6) break;
			if (office[tmpY][tmpX] == 0) office[tmpY][tmpX] = -1;
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	


	cin >> n >> m;

	// 입력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> office[i][j];
		}
	}

	// 전체 탐색
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) {
	//		// cctv이면 
	//		if (office[i][j] >= 1 && office[i][j] <= 5) {
	//			switch (office[i][j])
	//			{
	//			case 1:
	//				cctv1(i, j);
	//				break;
	//			case 2:
	//				cctv2(i, j);
	//				break;
	//			case 3:
	//				cctv3(i, j);
	//				break;
	//			case 4:
	//				cctv4(i, j);
	//				break;
	//			case 5:
	//				cctv5(i, j);
	//				break;
	//			default:
	//				break;
	//			}
	//		}
	//	}
	//}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// cctv이면 
			if (office[i][j] == 5) cctv5(i, j);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// cctv이면 
			if (office[i][j] == 4) cctv4(i, j);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// cctv이면 
			if (office[i][j] == 3) cctv3(i, j);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// cctv이면 
			if (office[i][j] == 2) cctv2(i, j);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// cctv이면 
			if (office[i][j] == 1) cctv1(i, j);
		}
	}

	
	//cout << "\n";
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) {
	//		cout << office[i][j] << " ";
	//	}
	//	cout << "\n";
	//}

	// 전체 확인
	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (office[i][j] == 0) result++;
		}
	}
	cout << result;

}