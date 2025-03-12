// DP > 01Ÿ�� (1904��)
// Ǯ�� �ð� : 15 m



// ��� ������ ��� -> ��Ž, dp -> n�� ũ�� ŭ -> ���� dp => ���� �͵鿡�� ���� �͵��� �������� üũ������ҵ� 
// point1> ��� ���� -> 15746�� ���� ������ => ��ü������ ���Ҷ� ��� �����ָ鼭 ������ߵ�
// point2> ��Ģ ã�� -> [n] = [n-1] + [n-2]
//			n-2 ���϶� 00 �ٿ��ֱ� , n-1���϶� 1�ٿ��ֱ� => ��ȭ�� �ϼ� 


#include <iostream>
#include <vector>
using namespace std;


int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	vector<int> memo;
	int n;
	cin >> n;


	memo.resize(n + 1, -1);

	memo[0] = 1;
	memo[1] = 1;

	// memorization
	// [n] = [n-1] + [n-2]
	for (int i = 2; i <= n; ++i)
	{
		memo[i] = (memo[i - 1] + memo[i - 2]) % 15746;
	}

	cout << memo[n];


}