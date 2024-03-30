// µ¦ > 1.µ¦(10866¹ø)

#include <iostream>
#include <deque>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	deque<int> dq;
	string cmd;
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> cmd;
		if (cmd.compare("push_front") == 0) {
			cin >> tmp;
			dq.push_front(tmp);
		}
		else if (cmd.compare("push_back") == 0) {
			cin >> tmp;
			dq.push_back(tmp);
		}
		else if (cmd.compare("pop_front") == 0) {
			if (dq.size() == 0) cout << -1 << "\n";
			else {
				cout << dq.front() << "\n";
				dq.pop_front();
			}
		}
		else if (cmd.compare("pop_back") == 0) {
			if (dq.size() == 0) cout << -1 << "\n";
			else {
				cout << dq.back() << "\n";
				dq.pop_back();
			}
		}
		else if (cmd.compare("size") == 0) {
			cout << dq.size() << "\n";
		}
		else if (cmd.compare("empty") == 0) {
			cout << dq.empty() << "\n";
		}
		else if (cmd.compare("front") == 0) {
			if (dq.size() == 0) cout << -1 << "\n";
			else cout << dq.front() << "\n";
		}
		else if (cmd.compare("back") == 0) {
			if (dq.size() == 0) cout << -1 << "\n";
			else cout << dq.back() << "\n";
		}
	}


}