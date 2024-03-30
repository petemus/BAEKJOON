// �� > 2.ȸ���ϴ� ť(1021��)
// ���� �հ� �ڿ� ����, ������ ���� �Ͼ ��� ����ϱ� ����
// ���� �� ������ �Ϲ����� ť���� ���� ����ϴ� �� ������ �ξ� ������

// sol1> ���Ʈ ����.. -> 2�� ���� �̵� ���� 3�� ���� �̵� �� �߿� ���� ���� �� ����.
// index�� �̿��ؼ� ũ�� ���� �� ���� ��
// -> for ���� �̿��ؼ� find ���� ���� index �� left ũ�� size() - i �� right ũ��

#include <iostream>
#include <deque>
using namespace std;

void leftMove(deque<int>& dq) {
	dq.push_back(dq.front());
	dq.pop_front();
}
void rightMove(deque<int>& dq) {
	dq.push_front(dq.back());
	dq.pop_back();
}

int leftCount(deque<int> dq, int find) {
	int i = 0;
	while (dq.front() != find) {
		leftMove(dq);
		i++;
	}
	return i;
}
int rightCount(deque<int> dq, int find) {
	int i = 0;
	while (dq.front() != find) {
		rightMove(dq);
		i++;
	}
	return i;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	deque<int> dq;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		dq.push_back(i + 1);
	}

	int r, l;
	int find;
	int sum = 0;
	for (int i = 0; i < m; i++) {
		cin >> find;
		r = rightCount(dq, find);
		l = leftCount(dq, find);
		if (r < l) {
			while (dq.front() != find) {
				rightMove(dq);
				sum++;
			}
		}
		else {
			while (dq.front() != find) {
				leftMove(dq);
				sum++;
			}
		}
		dq.pop_front();
	}

	cout << sum;


	//cout << rightCount(dq, 3) << "\n";
	//cout << leftCount(dq, 3) << "\n";
	//for (int i = 0; i < n; i++) {
	//	cout << dq[i] << " ";
	//}
}