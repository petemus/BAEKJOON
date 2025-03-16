// Brute Force > ��� ���ϱ� (2501��)
// Ǯ�� �ð� : 5m
// �ð� ���⵵ : O(n) -> N�� 10,000���ϴϱ� �ִ� ����� 10,000 -> ��Ž ���� 


#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;


	// n�� �ϳ��� �������鼭 �װ� k��°�� ������ Ȯ��
	int index = 0;
	for (int i = 1; i <= n; ++i)
	{
		// ��� üũ
		if (n % i == 0)
		{
			// ���� üũ
			++index;
			if (index == k)
			{
				// k ������ ���� ��� ���
				cout << i;
			}
		}
	}

	// �ش��ϴ� ���� ������ 0 ���
	if (index < k)
	{
		cout << 0;
	}

}