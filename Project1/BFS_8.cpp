// BFS > 8.��ŸƮ��ũ(5014��)
// BFS�� �ִ� �Ÿ� ã�� ������ ���
#include <iostream>
#include <queue>
using namespace std;

int BFS(int f, int s, int g, int u, int d) {

	bool visited[1000001] = { 0, };
	queue<pair<int, int>> q;
	int dir[] = {u, -d};

	q.push(make_pair(s, 0));
	visited[s] = 1;

	pair<int, int> tmp;
	int tmpP;
	while (!q.empty()) {
		tmp = q.front();
		// ���� ����
		if (tmp.first == g) return tmp.second;
		for (int i = 0; i < 2; i++) {
			tmpP = tmp.first + dir[i];
			if (tmpP <= 0 || tmpP > f) continue;
			if (!visited[tmpP]) {
				q.push(make_pair(tmpP, tmp.second + 1));
				visited[tmpP] = 1;
			}
		}
		//
		q.pop();
	}
	// ť�� �� ������ ã�� ���ϸ� -1
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;

	int result;
	result = BFS(f, s, g, u, d);
	if (result < 0) cout << "use the stairs";
	else cout << result;
}