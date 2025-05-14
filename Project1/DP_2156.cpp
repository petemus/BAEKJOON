// DP > ������ �ý�(2156��)
// Ǯ�� �ð� : 30m (Ʋ�� ���� ã���� �� �ɸ� 

// ����) �����ָ� �������� 3�� ������ + �ִ�� ���� ���� ������ ���� => dp

// ! ��ȭ�� ���� ��ġ�� �ʵ��� �� ������ ��!!!!!


#include <iostream>
#include <algorithm> // max(), min(), max({}) 
using namespace std;

// ���ΰ� ���� 
int wines[10002];

// 1�� ���� �� ����
int drink1[10002];
// 2�� ���� �� ���� 
int drink2[10002];
// �� ���� �� ���� 
int ndrink[10002];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// input
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> wines[i];
	}

	// �ʱ�ȭ
	drink1[1] = wines[1];
	drink2[1] = 0;
	ndrink[1] = 0;

	for (int i = 2; i <= n; ++i)
	{
		// ������ ���� ������ ���� �� ���� �߿� �ִ�� �� 
		// @@@@ ���� ������ ������ �ʵ��� ��ȭ�� �� ������ �ҵ� 
		ndrink[i] = max(ndrink[i - 1], max(drink1[i - 1], drink2[i - 1]));
		// 1�� ���� ������ ������ ���� ���� �߿� ����
		drink1[i] = ndrink[i - 1] + wines[i];
		// 2�� ���� ������ ������ �ѹ� ���� ���ο� ������
		drink2[i] = drink1[i - 1] + wines[i];
	}

	// ���� ���� ���� �� ����
	//cout << max({ndrink[n], drink1[n], drink2[n]});
	cout << max(max(ndrink[n], drink1[n]), drink2[n]);

}