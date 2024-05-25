// Backtracking > 스도쿠 (2580번)
// 풀이 시간 : 2 h (풀이 방법은 빨리 생각해냈지만 시간 문제와 예외 문제로 시간이 더 걸림)

// 브루트 포스 -> 시간이 너무 오래걸릴듯 X
// 벡트랙킹 -> 가로, 세로, 정사각형 세가지 체크후 가능한 것들로만 백트랙킹 
// -> 백트랙킹할 때마다 검사해주면 오래걸림 => 가로, 세로, 박스에 대해 변수를 가지는 게 좋음


#include <iostream>
using namespace std;

int sudoku[9][9];
bool isFinish = false;

// 가로, 세로, 사각형 나눠서  변수로 갖고 있는게 나을듯
bool colNum[9][10] = { false, };
bool rowNum[9][10] = { false, };
bool boxNum[3][3][10] = { false, };

// 함수 전방선언
bool isFull();
void printSudoku();



void Backtraking()
{
	// 한번만 출력
	if (isFinish) return;

	// 종료 조건 -> 스도쿠가 다 채워져 있을때, 들어갈 숫자를 찾지 못할 때 
	// 스도쿠가 다 채워져있을 때 출력 + 한번만 출력 
	if (isFull())
	{
		printSudoku();
		isFinish = true;
		return;
	}

	// 빈칸 찾기
	// 들어갈 수 있는 숫자 찾기
	// Backtracking
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (sudoku[i][j] == 0)
			{
				// 가능한 숫자 찾아주기 
				for (int k = 1; k < 10; k++)
				{
					bool a = colNum[j][k];
					bool b = rowNum[i][k];
					bool c = boxNum[(i / 3)][(j / 3)][k];
					if (!colNum[j][k] && !rowNum[i][k] && !boxNum[(i / 3)][(j / 3)][k])
					{
						sudoku[i][j] = k;
						colNum[j][k] = true;
						rowNum[i][k] = true;
						boxNum[(i / 3)][(j / 3)][k] = true;
						Backtraking();
						sudoku[i][j] = 0;
						colNum[j][k] = false;
						rowNum[i][k] = false;
						boxNum[(i / 3)][(j / 3)][k] = false;
					}
				}
				// 못찾으면 return
				return;
			}
		}
	}

}

bool isFull()
 {	
	bool full = true;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (sudoku[i][j] == 0) full = false;
		}
	}
	return full;
}

void printSudoku()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << sudoku[i][j] << " ";
		}
		cout << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> sudoku[i][j];
		}
	}
	
	// 가로, 세로, 사각형 초기화
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			int k = sudoku[i][j];
			if (k > 0)
			{
				colNum[j][k] = true;
				rowNum[i][k] = true;
				boxNum[(i / 3)][(j / 3)][k] = true;
			}
		}
	}

	// Backtraking 
	Backtraking();

	
}