// Backttracking > ������ �����ֱ� (14888��)
// Ǯ�� �ð� : 

// ������ �ߺ� �Ǹ� X -> ��Ʈ��ŷ

#include <iostream>
using namespace std;

int n;
int minHap = 1000000000;	// �ּڰ�
int maxHap = -1000000000;	// �ִ�
// ����
int num[11];
int oper[4]; // 0 : ���� , 1 : ����, 2 : ��, 3 : ����
int operArr[10];	// ������ �迭 

enum Operator
{
	PLUS = 0,
	MINUS,
	MULTIPLY,
	DIVIDE
};

void Backtracking(int operCount)
{
	// ���� ���� : operCount �� n-1 ���϶�
	if (operCount == n - 1)
	{
		// �� ��� + min, max Update
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
		// �����ڰ� ������ Backtracking
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

	// �Է�
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

	// ���
	cout << maxHap << "\n" << minHap;

}