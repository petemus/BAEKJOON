// �� ������, ������ > ����(2559��)
// Ǯ�� �ð� : 20m
// �������� ��ĥ ������ �µ��� ���� ���� ū ��
// start, end�� index�� �˰� ������ �ѹ� ���� �ָ� �� ���Ĵ� ��� �װ����� �����ְ� ���ָ� �ȴ�



#include <iostream>
#include <vector>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<int> temperature(n);
	for (int i = 0; i < n; i++)
	{
		cin >> temperature[i];
	}

	// �� ������ (start�� end�� ���� �� �ִ�)
	int start = 0, end = -1;
	// �ּڰ��� �µ��� �ּ� �� * 10��
	int maxSum = 0;
	// ������
	int sum = 0;

	// ó���� k��ŭ ������
	for (int i = 0; i < k; i++)
	{
		sum += temperature[++end];
	}
	maxSum = sum;

	// n - k�� ��ŭ �ݺ�
	for (int i = 1; i <= n - k; i++)
	{
		// start, end ����
		// start : ���� ����
		// end : �����ϰ� ����
		sum -= temperature[start++];
		sum += temperature[++end];

		if(sum > maxSum) maxSum = sum;
	}


	cout << maxSum;
}
