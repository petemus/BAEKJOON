// ť > 1.ť(10845��) 2.ť2(18258��)

// ! �ڷᱸ���� ��Ұ� ���� ��� peek�� pop�� �� ��� ����

#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	queue<int> q;
	string cmd;
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> cmd;
		if (cmd.compare("push") == 0) {
			cin >> tmp;
			q.push(tmp);
		}
		else if (cmd.compare("pop") == 0) {
			if (q.size() == 0) cout << -1 << "\n";
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (cmd.compare("size") == 0) {
			cout << q.size() << "\n";
		}
		else if (cmd.compare("empty") == 0) {
			cout << q.empty() << "\n";
		}
		else if (cmd.compare("front") == 0) {
			if (q.size() == 0) cout << -1 << "\n";
			else cout << q.front() << "\n";
		}
		else if (cmd.compare("back") == 0) {
			if (q.size() == 0) cout << -1 << "\n";
			else cout << q.back() << "\n";
		}
	}


}