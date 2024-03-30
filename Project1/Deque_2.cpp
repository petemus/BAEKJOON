// 덱 > 2.회전하는 큐(1021번)
// 덱은 앞과 뒤에 삽입, 삭제가 많이 일어날 경우 사용하기 좋음
// 따라서 이 문제는 일반적인 큐보다 덱을 사용하는 게 성능이 훨씬 좋을듯

// sol1> 브루트 포스.. -> 2번 연산 이동 수와 3번 연산 이동 수 중에 적은 연산 수 적용.
// index를 이용해서 크기 구할 수 있을 듯
// -> for 문을 이용해서 find 값을 갖는 index 가 left 크기 size() - i 가 right 크기

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