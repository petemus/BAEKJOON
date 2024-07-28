// Backtracking > 스타트와 링크(14889번)
// 풀이 시간 : 7 13


// checkpoint
// 1> 시간 초과 -> 모든 재귀 문제가 그렇듯 n이 조금만 커지더라도 연산 수가 매우 커짐 => 주의
//	sol1> Backtracking 반복문을 1번쨰부터가 아니라 내가 현재 선택한 수의 다음 수부터 선택  
//  sol2> 반복되는지 매번 함수 호출을 통해서 체크해주는 것이 아니라 isVisited 같은 변수를 통해서 체크해주는 게 더 시간 효율이 좋음


#include <iostream>
using namespace std;

int n;
int ability[21][21] = { 0, };

int minGap = 100000;
int teamA[11] = { 0, };		// team의 index가 들어감

bool isTeamA(int num)
{
	// team 배열에 있는지 확인해주는 함수
	bool isFind = false;
	for (int i = 1; i <= n; i++)
	{
		if (teamA[i] == num) isFind = true;
	}

	return isFind;
}

void Backtraking(int teamNum)
{
	// 종료 조건
	if (teamNum == n / 2)
	{
		int teamASum = 0, teamBSum = 0;
		// 0~n-1 인덱스의 사람들 확인
		for (int i = 1; i <= n; i++)
		{
			// 같은 팀에 있는 사람들만 계산
			for (int j = i + 1; j <= n; j++)
			{
				if (isTeamA(i) && isTeamA(j))
				{
					// 같은 팀 확인
					teamASum += ability[i][j];
					teamASum += ability[j][i];
				}
				else if (!isTeamA(i) && !isTeamA(j))
				{
					teamBSum += ability[i][j];
					teamBSum += ability[j][i];
				}
			}
		}
		// 최소인지 확인
		if (abs(teamASum - teamBSum) < minGap) minGap = abs(teamASum - teamBSum);
		return;
	}

	// isVisited 변수 만들어도 되고 isTeam 사용해도 되고 
	for (int i = 1 + teamA[teamNum]; i <= n; i++)
	{
		if (!isTeamA(i))
		{
			// 팀에 소속되어 있지 않으면 backtracking
			teamA[teamNum + 1] = i;
			Backtraking(teamNum + 1);
		}
	}


}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 입력
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> ability[i][j];
		}
	}


	// Backtracking
	// > 인원 선택
	// > 다 선택하고 능력치 차이 계산
	Backtraking(0);

	// 출력
	cout << minGap;
}