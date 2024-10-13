// DP > 1�� �����(1463��)
// 3���� ������ ����� 2�� ������ ������ ��ġ�� �κ�(overlapping problem)�� �߻��Ѵ�
// 6���� ������ �������� �κ��� ��ħ -> DP

// ���� �κ� ����(Optimal Substructure), ��ġ�� �κ� ���� (Overlapping subproblem)


#include <iostream>
#include <memory.h>
using namespace std;

// index�� 1�� �ɶ��� �ּ� ����� 
int memo[1000001];

// Top-Down ���
int Recur(int i)
{
	// �̹� �湮�� ���̸� return
	if(memo[i] != -1) return memo[i];

	int m = Recur(i - 1);

	if(i % 2 == 0) m = min(m, Recur(i / 2));
	if(i % 3 == 0) m = min(m, Recur(i / 3));

	// �ּڰ� ã�� �� ����
	return memo[i] = m + 1;

}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	
	cin >> n;

	// ����Ʈ ������ �ʱ�ȭ ���ִ� ��
	memset(memo, -1, 1000001 * sizeof(int));

	memo[1] = 0;
	Recur(n);



	// Bottom-up ���
	//for (int i = 2; i <= n; i++)
	//{
	//	int m = memo[i - 1];
	//	if (i % 2 == 0) m = min(m, memo[i / 2]);
	//	if (i % 3 == 0) m = min(m, memo[i / 3]);

	//	memo[i] = m + 1;
	//}

	cout << memo[n];

}