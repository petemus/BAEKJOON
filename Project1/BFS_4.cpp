// BFS > 4.���ڲ���(1679��)

// 1�� �ñ�> �޸� �ʰ���. -> ��� ��츦 ť�� �־ �׷���. Ư�� ������ �� �־���ҵ�
// -> q�� �̹� �ִ� ���̸� ť�� ���� �ʿ� ����.
// 2�� > �޸� �ʰ���. -> set�� ���� �ߺ��� ���� ť�� �� �־��ֵ��� �ߴµ� ����
// 3�� > Ʋ�� -> 10 �� �Ʒ��� ���� ����. 0 �̻� ����. 
// -> ������ ������ �ִµ�
// => 10�� �Ʒ��� �ִ� ���� �����ϸ� �ּ� ��� �� ���ϴ� ��쵵 ����.
// 10���� 2�� ���� ����..

#include <iostream>
#include <queue>
using namespace std;

int BFS(int n, int k) {

	// ������ �ִ� ������ Ȯ�����ֱ� ���� set
	bool exist[200001] = { 0, };

	// first�� ��ġ, second�� leel
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
		// ���� ������ return
		if (tmp.first == k) {
			//cout << cnt << "\n";
			return tmp.second;
		}
		// -1 , +1, *2 ��츦 ��� q�� �־���
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