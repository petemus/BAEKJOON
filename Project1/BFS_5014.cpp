// BFS > 스타트링크(5014번)
// isVisited 배열 없으면 계속 반복 

#include <iostream>
#include <queue>
using namespace std;


int BFS(int f, int s, int g, int u, int d)
{
	bool isVisited[1000001] = { false, };


	// 못 찾음 
	return -1;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int f, g, s, u, d;
	cin >> f >> s >> g >> u >> d;

	int result = BFS(f, s, g, u, d);

	// 성공
	if (result > 0) cout << result;
	else cout << "use the stairs";

}





































































//int BFS(int f, int s, int g, int u, int d) {
//
//	bool visited[1000001] = { 0, };
//	queue<pair<int, int>> q;
//	int dir[] = {u, -d};
//
//	q.push(make_pair(s, 0));
//	visited[s] = 1;
//
//	pair<int, int> tmp;
//	int tmpP;
//	while (!q.empty()) {
//		tmp = q.front();
//		// 종료 조건
//		if (tmp.first == g) return tmp.second;
//		for (int i = 0; i < 2; i++) {
//			tmpP = tmp.first + dir[i];
//			if (tmpP <= 0 || tmpP > f) continue;
//			if (!visited[tmpP]) {
//				q.push(make_pair(tmpP, tmp.second + 1));
//				visited[tmpP] = 1;
//			}
//		}
//		//
//		q.pop();
//	}
//	// 큐가 빌 때까지 찾지 못하면 -1
//	return -1;
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	int f, s, g, u, d;
//	cin >> f >> s >> g >> u >> d;
//
//	int result;
//	result = BFS(f, s, g, u, d);
//	if (result < 0) cout << "use the stairs";
//	else cout << result;
//}