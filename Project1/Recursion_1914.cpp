// Recursion > �ϳ��� ž (1914��)
// Ǯ�� �ð� : 8 10
// vector�� �̵� ��� �����ҷ��� �ߴµ� ���� �� -> n�� 20���� ũ�� ��� ��� �����൵ ��

// @ �ϳ���ž �ּ� �̵� Ƚ�� 2^n - 1
// @ pow�� ��ȯ���� �Ǽ�����

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
	
	// ���
	cout << s << '\n';
	if (n <= 20)
	{
		Hanoi(n, 1, 2, 3);
	}


}