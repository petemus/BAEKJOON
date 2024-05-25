// Backtracking > ������ (2580��)
// Ǯ�� �ð� : 2 h (Ǯ�� ����� ���� �����س����� �ð� ������ ���� ������ �ð��� �� �ɸ�)

// ���Ʈ ���� -> �ð��� �ʹ� �����ɸ��� X
// ��Ʈ��ŷ -> ����, ����, ���簢�� ������ üũ�� ������ �͵�θ� ��Ʈ��ŷ 
// -> ��Ʈ��ŷ�� ������ �˻����ָ� �����ɸ� => ����, ����, �ڽ��� ���� ������ ������ �� ����


#include <iostream>
using namespace std;

int sudoku[9][9];
bool isFinish = false;

// ����, ����, �簢�� ������  ������ ���� �ִ°� ������
bool colNum[9][10] = { false, };
bool rowNum[9][10] = { false, };
bool boxNum[3][3][10] = { false, };

// �Լ� ���漱��
bool isFull();
void printSudoku();



void Backtraking()
{
	// �ѹ��� ���
	if (isFinish) return;

	// ���� ���� -> ������ �� ä���� ������, �� ���ڸ� ã�� ���� �� 
	// ������ �� ä�������� �� ��� + �ѹ��� ��� 
	if (isFull())
	{
		printSudoku();
		isFinish = true;
		return;
	}

	// ��ĭ ã��
	// �� �� �ִ� ���� ã��
	// Backtracking
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (sudoku[i][j] == 0)
			{
				// ������ ���� ã���ֱ� 
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
				// ��ã���� return
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
	
	// ����, ����, �簢�� �ʱ�ȭ
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