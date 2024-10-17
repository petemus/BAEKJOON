// DP > ���� ū �����ϴ� �κ� ����(11055)
// start : 50


#include <iostream>
#include <memory.h>
using namespace std;

// i ���� ���� �ε������� i���� ���� ���� ã���� �� + �ڱ� �ڽ��� �ڱ� �ִ�

// �ڱ� �ڽ��� �����ϴ� �����ϴ� �κ� ���� ��
int memo[1001];
int arr[1001];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// input
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}


	memset(memo, -1, sizeof(int));

	// �ʱⰪ
	memo[1] = arr[1];

	// �ִ� ũ�� ����
	// !! �ִ밪 �̷��� �׻� ����� �ִ� �� ����...
	int m = memo[1];
	for (int i = 2; i <= n; i++)
	{
		// ���� ������ ���� �༮ ã���ֱ�
		// !! ���� �༮�� �߿��� �ִ��� �༮�� �����ֱ� 
		int subMax = 0;
		for (int j = i - 1; j > 0; j--)
		{
			if (arr[i] > arr[j])
			{
				subMax = max(subMax, memo[j]);
			}
		}
		memo[i] = subMax + arr[i];

		// �ִ� ��
		if(memo[i] > m) m = memo[i];
	}

	cout << m;

}