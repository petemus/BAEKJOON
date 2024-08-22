// Backtracking > 사다리 조작(15684번)
// checkpoint
// 1) 다리의 결과값을 어떻게 구할지
// 2) 연속되어 있는 곳에는 다리를 두면 안됨

// Backtracking
// 빈 곳 다리 놓고 체크
// 안되면 다리 또 놓기
// 최솟값 구하기 
// 3 넘어가면 걍 return + 실패하면 -1

// ?
// 다리가 어디로 도착하는지 어떻게 아나
// verLine으로 판단 row 순서로 내려가보면서 
// 연결되어 있으면 현재 Line이 내 라인이면 성공 


#include <iostream>
using namespace std;

// 가로선의 정보 배열 (a, b)로 표현 (a번 위치에서 b~b+1 사이를 연결)
// 가로선 정보 배열 크기 : h * (n -1)개 (최대 270)
// 값 0 : 연결 X, 값 1 : 연결 
int horLine[31][10] = { 0, };

int n, m, h;
int minLine = -1;

bool isSuccess()
{
	// i번의 결과가 i번 다 나오는지 체크
	bool isSuccess = true;

	// 한 개라도 실패하면 false 반환
	for (int i = 1; i <= n; i++)
	{
		int nowLine = i;
		for (int j = 1; j <= h; j++)
		{
			
			if (nowLine < n && horLine[j][nowLine])
			{
				// 라인 있으면 그쪽으로 옮김
				nowLine++;
				continue;
			}

			if (nowLine > 1 && horLine[j][nowLine - 1])
			{
				// 라인 있으면 그쪽으로 옮김
				nowLine--;
				continue;
			}

		}

		// 마지막 라인이 같지 않으면 실패
		if(nowLine != i) return false;
	}
	return true;
}

void Backtracking(int lineCnt, int y, int x)
{
	// 종료 조건 1
	// 추가 해야하는 가로선이 3보다 크면 -1 저장
	if (lineCnt >= 4)
	{
		return;
	}
	// 종료 조건 2
	// 모든 라인이 i에서 i로 갈때 성공
	if (isSuccess())
	{
		if(lineCnt < minLine || minLine < 0) minLine = lineCnt;
		return;
	}

	// line 둘 수 있는 곳에 라인 두기 
	for (int i = y; i <= h; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if(i == y && j == 1) j = x;

			// 연속 되어 있으면 continue
			if (j > 1 && horLine[i][j - 1]) continue;
			if(j < n - 1 && horLine[i][j + 1]) continue;
			
			if (!horLine[i][j])
			{
				horLine[i][j] = 1;
				Backtracking(lineCnt + 1, i, j);
				horLine[i][j] = 0;
			}
		}
	}
}


int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	cin >> n >> m >> h;

	for (int  i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		horLine[a][b] = 1;
	}

	Backtracking(0, 1, 1);

	cout << minLine;
}