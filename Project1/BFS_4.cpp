// BFS > 4.숨박꼭질(1679번)

// 1차 시기> 메모리 초과남. -> 모든 경우를 큐에 넣어서 그런듯. 특정 조건을 더 넣어야할듯
// -> q에 이미 있는 값이면 큐에 넣을 필요 없음.
// 2차 > 메모리 초과남. -> set을 만들어서 중복된 값은 큐에 안 넣어주도록 했는데 실패
// 3차 > 틀림 -> 10 만 아래의 값만 저장. 0 이상만 저장. 
// -> 논리적인 오류가 있는듯
// => 10만 아래에 있는 값만 저장하면 최소 경로 못 구하는 경우도 생김.
// 10만의 2배 까지 저장..

#include <iostream>
#include <queue>
using namespace std;

int BFS(int n, int k) {

	// 기존에 있는 값인지 확인해주기 위한 set
	bool exist[200001] = { 0, };

	// first는 위치, second는 leel
	queue<pair<int, int>> q;
	q.push(make_pair(n, 0));
	exist[n] = 1;
	
	pair<int,int> tmp;
	int sec = 0;
	int tF, tS;
	int cnt = 1;

	while (!q.empty()) {
		tmp = q.front();
		//cout << "tmp : " << tmp.first << " \n";
		// 값이 같으면 return
		if (tmp.first == k) {
			//cout << cnt << "\n";
			return tmp.second;
		}
		// -1 , +1, *2 경우를 모두 q에 넣어줌
		tF = tmp.first;
		tS = tmp.second;
		if ((tF + 1) <= 2 * k && !exist[tF+1]) {
			q.push(make_pair(tF + 1, tS + 1));
			exist[tF + 1] = 1;
			cnt++;
		}
		if ((tF - 1) >= 0 && !exist[tF - 1]) {
			q.push(make_pair(tF - 1, tS + 1));
			exist[tF - 1] = 1;
			cnt++;
		}
		if ( (tF * 2) <= 2 * k && !exist[tF * 2] ) {
			q.push(make_pair(tF * 2, tS + 1));
			exist[tF * 2] = 1;
			cnt++;
		}
		// pop
		q.pop();
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	cout << BFS(n, k);

}