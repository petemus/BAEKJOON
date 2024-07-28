// Graph Search > A -> B (16953번)
// 풀이 시간 :
// long long으로 해줘야함 => int 형과 연산을 한 결과값이 int형으로 나오기 때문에 값이 잘못나옴 => 오류 

#include <iostream>
#include <queue>
using namespace std;

int BFS(int a, int b)
{
	// first -> 연산된 수  second -> 연산횟수
	queue<pair<long, long>> q;
	q.push({a, 1});

	while (!q.empty())
	{
		pair<long, long> now = q.front();
		q.pop();

		// 종료 조건 확인 
		if (now.first == b) return now.second;

		if (now.first * 2 <= b) q.push({ now.first * 2, now.second + 1 });
		if(now.first * 10 + 1 <= b) q.push({ now.first * 10 + 1, now.second + 1 });
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b;
	cin >> a >> b;

	//cout << BFS(a, b);
	cout << a * 10;

}

