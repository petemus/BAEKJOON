// Recursion > 2.하노이 탑(11729번)

#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> path;

void Hanoi(int n, int from, int by, int to) {
	// 종료 조건
	if (n == 1) path.push_back(make_pair(from, to));
	else {
		Hanoi(n - 1, from, to, by);
		path.push_back(make_pair(from, to));
		Hanoi(n - 1, by, from, to);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	Hanoi(n, 1, 2, 3);

	cout << path.size() << "\n";
	for (int i = 0; i < path.size(); i++) {
		cout << path[i].first << " " << path[i].second << "\n";
	}

}