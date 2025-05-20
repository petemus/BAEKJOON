// 누적합(Prefix Sum), DP! > 구간 합 구하기 5
// 풀이 시간 : 40~50m 
// !!! 시간, edge case 신경써서

// 누적합 배열이 2차원임 (사각형 형태로)
// 완탐으로 할려면 연산 속도 1억 조금 넘음 

// #풀이
// ! 누적합을 이용해서 어떻게 (n,m) 구간까지의 합을 구할 것인가 + 1차원과는 다른 방법 
// (0, 0) ~ (n, m) 까지의 합을 저장해놓은 누적합 만들고
//  _ _ _ _
//	_ D _ C
//  _ B _ A  일때 (2, 3) ~ (2, 4) 를 구할려면 => A - B - C + D 를 통해서 구하면 됨 


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

			// 누적합 저장 
			// 2. A + B - C + arr[i][j]
			int a = 0, b = 0, c = 0;
			// @@@@사실상 i = 0, j = 0일때는 모두 0이여서 if문 안써도 됨 ㅜ
			if(j > 1)
				a = prefix[i][j - 1];
			if(i > 1)
				b = prefix[i - 1][j];
			if(i > 1 &&  j > 1)
				c = prefix[i - 1][j - 1];

			prefix[i][j] = a + b - c + arr[i][j];

		}
	}


	// 누적합 구하기
	while (m--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		// 누적합 반환
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