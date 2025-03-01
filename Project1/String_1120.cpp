// 문자열, 완탐 > 문자열(1120번)
// 풀이 시간 : 8 20


// 완탐 ? 백트랙킹? -> 앞 뒤 삽입의 모든 경우의 수 체크 후 최소 출력 => X 불필요
// 기존 문자열은 그대로이므로 그 문자열이 이동하면서 최소인 구간 찾으면 됨 


#include <iostream>
using namespace std;


int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// a 길이 <= b 길이
	string a, b;
	cin >> a >> b;

	int minDis = 50;
	for (int i = 0; i <= (b.size() - a.size()); ++i)
	{
		int dis = 0;
		for (int j = 0; j < a.size(); ++j)
		{
			if (a[j] != b[i + j])
			{
				++dis;
			}
		}

		// 최솟값 비교
		if(minDis > dis) minDis = dis;

	}

	cout << minDis;


}