// 3.퇴사(14501) => O
// overlapping subproblem, optimal substrutcture ->  N일에서의 최대 수익은 N-1일에서의 최대 수익 + 자기 자신
// ?? 너무 예외처리를 많이 했는데 이렇게 푸는 게 맞을까?


#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	// 가변 배열 vector 생성
	vector<pair<int, int>> cal;
	int calNote[16] = {};

	for (int i = 0; i < n; i++) {
		int t, p;
		cin >> t >> p;
		cal.push_back({ t, p });
		calNote[i] = p;
	}

	// 한개씩 비교 -> 이때 최대 일수 보다 작은지 예외 처리 해줘야함
	// 한개씩 왼쪽에 있는 값들이랑 비교

	int maxPay = 0;

	for (int i = 0; i < n; i++)
	{
		// 현재 날짜가 최대 날짜를 초과하지 않는지 비교 
		if ((i + cal[i].first) > n) continue;
		// 왼쪽에 있는 날짜들이랑 값 비교
		for (int j = i - 1; j >= 0; j--)
		{
			// 왼쪽에 있는 날짜들이 현재 날짜를 초과하지 않는지 검사
			if ((j + cal[j].first) > i) continue;
			// 안 초과하면 현재 노트 값과 비교
			if ((calNote[j] + cal[i].second) > calNote[i]) calNote[i] = calNote[j] + cal[i].second;
		}

		// maxPay 값 갱신
		if (maxPay < calNote[i]) maxPay = calNote[i];
	}

	cout << maxPay;


}