// BFS > 14.���ڲ���3(13549��)
// ���� ���ڲ������� �ð��� ����ϴ� ����
// ������ ���� �����ϰ� �ð��� �ٲٸ� �ɵ�

// ���2) �ڷ���Ʈ ��θ� ���� ť�� �ִ� ���.

#include <iostream>
#include <queue>
using namespace std;

int BFS(int n, int k) {

	// ��, (����, �ð�)
	queue<pair<int, pair<int, int>>> q;
	bool isVisited[200001] = { 0, };
	int visitedSec[200001] = { 0, };

	q.push(make_pair(n, make_pair(0, 0)));
	isVisited[n] = 1;
	visitedSec[n] = 0;

	pair<int, pair<int, int>> tmp;
	int tmpD, tmpS, tmpL;
	int minSec = 0 , minLevel;
	while (!q.empty()) {
		tmp = q.front();
		//cout << "tmpFirst : " << tmp.first << " | sec, level : " << tmp.second.second << " " << tmp.second.first << "\n";
		if (tmp.first == k) {
			minLevel = tmp.second.first;
			minSec = tmp.second.second;
			break;
		}
		int dirDis[3] = { tmp.first * 2, tmp.first + 1, tmp.first - 1 };
		int dirSec[3] = { 0, 1, 1 };
		for (int i = 0; i < 3; i++) {
			tmpD = dirDis[i];
			tmpS = dirSec[i] + tmp.second.second;
			tmpL = tmp.second.first + 1;
			if (tmpD < 0 || tmpD > 200000) continue;
			//cout << tmp.first << " : ���� sec, ���� sec " << visitedSec[tmpD] << " " << tmpS << "\n";
			if (!isVisited[tmpD]) {
				isVisited[tmpD] = 1;
				visitedSec[tmpD] = tmpS;
				q.push(make_pair(tmpD, make_pair(tmpL, tmpS)));
			}
			else if (visitedSec[tmpD] > tmpS) {
				visitedSec[tmpD] = tmpS;
				q.push(make_pair(tmpD, make_pair(tmpL, tmpS)));
			}
		}
		q.pop();
	}
	// ������ �ּ� �ð��� �ִ��� Ȯ��
	//cout << "\n";
	while (!q.empty()) {
		tmp = q.front();
		//cout << "tmpFirst : " << tmp.first << " | sec, level : " << tmp.second.second << " " << tmp.second.first << "\n";
		if (tmp.second.first != minLevel) return minSec;
		if (tmp.first == k) {
			if (tmp.second.second < minSec) minSec = tmp.second.second;
		}
		q.pop();
	}
	return minSec;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	cout << BFS(n, k);
}