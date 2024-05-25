// Backttracking > 연산자 끼워넣기 (14888번)
// 풀이 시간 : 

// 연산자 중복 되면 X -> 백트랙킹

#include <iostream>
using namespace std;

int n;
int minHap = 1000000000;	// 최솟값
int maxHap = -1000000000;	// 최댓값
// 수열
int num[11];
int oper[4]; // 0 : 덧셈 , 1 : 뺄셈, 2 : 곱, 3 : 나눗
int operArr[10];	// 연산자 배열 

enum Operator
{
	PLUS = 0,
	MINUS,
	MULTIPLY,
	DIVIDE
};

void Backtracking(int operCount)
{
	// 종료 조건 : operCount 가 n-1 개일때
	if (operCount == n - 1)
	{
		// 값 계산 + min, max Update
		int val = num[0];
		for (int i = 0; i < n - 1; i++)
		{
			switch (operArr[i])
			{
			case PLUS:
				val += num[i + 1];
				break;
			case MINUS:
				val -= num[i + 1];
				break;
			case MULTIPLY:
				val *= num[i + 1];
				break;
			case DIVIDE:
				val /= num[i + 1];
				break;
			default:
				break;
			}
		}
		if (maxHap < val) maxHap = val;
		if (minHap > val) minHap = val;
		return;
	}

	// Backtracking
	for (int i = 0; i < 4; i++)
	{
		// 연산자가 있으면 Backtracking
		if (oper[i] > 0)
		{
			oper[i]--;
			operArr[operCount] = i;
			Backtracking(operCount + 1);
			oper[i]++;
		}
	}

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 입력
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}

	for (int i = 0; i < 4; i++)
	{
		cin >> oper[i];
	}

	// Backtracking
	Backtracking(0);

	// 출력
	cout << maxHap << "\n" << minHap;

}