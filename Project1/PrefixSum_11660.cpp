// ������(Prefix Sum), DP! > ���� �� ���ϱ� 5
// Ǯ�� �ð� : 40~50m 
// !!! �ð�, edge case �Ű�Ἥ

// ������ �迭�� 2������ (�簢�� ���·�)
// ��Ž���� �ҷ��� ���� �ӵ� 1�� ���� ���� 

// #Ǯ��
// ! �������� �̿��ؼ� ��� (n,m) ���������� ���� ���� ���ΰ� + 1�������� �ٸ� ��� 
// (0, 0) ~ (n, m) ������ ���� �����س��� ������ �����
//  _ _ _ _
//	_ D _ C
//  _ B _ A  �϶� (2, 3) ~ (2, 4) �� ���ҷ��� => A - B - C + D �� ���ؼ� ���ϸ� �� 


#include <iostream>	
using namespace std;

int arr[1026][1026] = {0,};
int prefix[1026][1026] = {0,};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m; 
	
	// input
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> arr[i][j];

			// ������ ���� 
			// 2. A + B - C + arr[i][j]
			int a = 0, b = 0, c = 0;
			// @@@@��ǻ� i = 0, j = 0�϶��� ��� 0�̿��� if�� �Ƚᵵ �� ��
			if(j > 1)
				a = prefix[i][j - 1];
			if(i > 1)
				b = prefix[i - 1][j];
			if(i > 1 &&  j > 1)
				c = prefix[i - 1][j - 1];

			prefix[i][j] = a + b - c + arr[i][j];

		}
	}


	// ������ ���ϱ�
	while (m--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		// ������ ��ȯ
		int a = 0, b = 0, c = 0, d = 0;
		a = prefix[x2][y2];
		if(y1 > 1)
			b = prefix[x2][y1 - 1];
		if(x1 > 1)
			c = prefix[x1 - 1][y2];
		if(x1 > 1 && y1 > 1)
			d = prefix[x1 - 1][y1 - 1];

		int sum = a - b - c + d;
		cout << sum << '\n';
	}



}