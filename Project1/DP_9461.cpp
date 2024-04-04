// 1. �ĵ��� ����(9461)
// ?? ���ﰢ���� � ������� �þ���� ���ذ� �Ȱ�
// sol1) ������ ���� ��Ģ�� ã�Ƽ� Ǯ�� -> dp ���
// a4 = a1 + a2 , a5 = a2 + a3, a6 = a3 + a4 => a(n) = a(n-2) + a(n-3)

// sol2) �Ǻ���ġ ������ ����ؼ� �Ǻ���ġ ���� Ǫ�� ������� Ǯ �� ���� ��

#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testCase;
	cin >> testCase;

	long long triangle[151] = { 0, 1, 1, 1, };
	for (int i = 4; i < 151; i++)
	{
		triangle[i] = triangle[i - 2] + triangle[i - 3];
	}


	// n�� ���� ������ triangle�� ���� �����ָ� ����(���嵵 �� �� �����ϱ�)
	// sol1) 150������ triangle�� �� ���ϰ� �Է°� ������ ��� -> ���
	// -> n�� ���� Ŀ������ triagnel�� ���� �޼������� �����ؼ� int�� ǥ�� �Ұ��ѵ�
	// sol2) ���� ���� �����ϰ� �� ������ ū ���� ������ �׶� ���

	int n;
	while (testCase--)
	{
		cin >> n;
		cout << triangle[n] << '\n';
	}


}