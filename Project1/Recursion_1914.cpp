// Recursion > 하노이 탑 (1914번)
// 풀이 시간 : 8 10
// vector로 이동 경로 저장할려고 했는데 문제 남 -> n이 20보다 크면 경로 출력 안해줘도 됨

// @ 하노이탑 최소 이동 횟수 2^n - 1
// @ pow의 반환값은 실수형임

#include <iostream> 
#include <math.h>
#include <string>
using namespace std;

void Hanoi(int n, int from, int by, int to)
{
	if (n == 1)
	{
		cout << from << " " << to << '\n';
		return;
	}
		
	Hanoi(n - 1, from, to, by);
	cout << from << " " << to << '\n';
	Hanoi(n - 1, by, from, to);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	string s = to_string(pow(2, n));

	int x = s.find('.');
	s = s.substr(0, x);	
	s[s.length() - 1] -= 1;
	
	// 출력
	cout << s << '\n';
	if (n <= 20)
	{
		Hanoi(n, 1, 2, 3);
	}


}