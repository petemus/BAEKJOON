// 큐 > 3.카드2(2164번)

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

	for (int i = 0; i < n; i++) {
		q.push(i + 1);
	}

	int tmp = 0;
	while (q.size() != 1)
	{
		q.pop();
		q.push(q.front());
		q.pop();		
	}

	cout << q.front();

}