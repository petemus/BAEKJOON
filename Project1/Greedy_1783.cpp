// Greedy > ���� ����Ʈ (1783��)

// �湮�� ĭ�� �� �ִ� 
// 4�� ���� ũ�� 4���� ��� ��� �ѹ��� ��� 

// ���� N * M
// ����Ʈ ��ġ : (n -1, 0)

// 1) + (-2, +1)
// 2) + (-1, +2)
// 3) + (+1, +2)
// 4) + (+2, +1)

// ! ������ +1 or +2�̰� -> ������ ��찡 ���� �� ���� => �׸��� 


#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	
	int result = 0;

	if (n >= 3 && m >= 7) result = m - 2;
	else if (n >= 3 && m < 7)
	{
		if (m >= 5) result = 4;
		else if (m < 5)  result = m;
	}
	else if (n == 2)
	{
		if (m <= 8) result = (m + 1) / 2;
		else result = 4;
	}
	else if (n == 1) result = 1;

	cout << result;
}