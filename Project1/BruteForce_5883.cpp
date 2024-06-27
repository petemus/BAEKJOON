// Brute Force > ������ 9s (5883��)
// Ǯ�� �ð� :
// 1) Brute Force : 1000 * 100�� -> �ִ� 10��(�ʰ�)
// 2) Brute Force (n * n)��ŭ Ž�� 1000 * 1000 -> 100��
// + ����� �������� �ʴ� ���� ���µ�

#include <iostream> 
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int arr[1000];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	// Brute Force 
	// ������� �ϳ��� �����ϰ� �ش� ���� �����ϰ� ���� ���̰� �� ���� ���� üũ
	// arr[i]�� ������ �뷮
	// ���� ���̰� �� ���� ���� üũ
	int maxLen = 0;
	for (int i = 0; i < n; i++)
	{
		int len = 0;
		int nowVal = 0;
		for (int j = 0; j < n; j++)
		{
			if (arr[j] == arr[i]) continue;

			if (nowVal == arr[j]) ++len;
			else
			{
				// �ٸ� ���ڰ� ������ �ִ� ���̶� �� + �ʱ�ȭ
				if (len > maxLen) maxLen = len;
				nowVal = arr[j];
				len = 1;
			}
		}

		// �ٸ� ���ڰ� ������ �ʰ� ������ �ִ밪 Ȯ�� �����ֹǷ� ���������� �ѹ� �� üũ
		if (len > maxLen) maxLen = len;
	}


	cout << maxLen;
}