// 비트 마스킹 > 집합 (11723번)
//
// 집합 안에 포함되어 있는 숫자의 유무를 비트로 표현


// & : AND 연산
// | : OR 연산
// ~ : Not 연산
// ^ : NOR 연산 (다르면 true / 같으면 false) 


#include <iostream>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int m;
	cin >> m;
	
	string command;
	int s = 0;			// s는 집합 
	while (m--)
	{
		cin >> command;
		int x; 
		if (command == "add")
		{
			cin >> x;
			s |= (1 << (x - 1)); // 0010000.. 이런식 그 비트값만 변경(0인 경우) 그대로(1인 경우)
		}
		else if (command == "check")
		{
			cin >> x;
			if(s & (1 << (x-1))) cout << '1' << '\n';
			else cout << '0' << '\n';
		}
		else if (command == "remove")
		{
			cin >> x;
			s &= ~(1 << (x - 1));
		}
		else if (command == "toggle")
		{
			cin >> x;
			s ^= ( 1 << (x - 1));
		}
		else if (command == "all")
		{
			s = (1 << 20) -1;
		}
		else if (command == "empty")
		{
			s = 0;
		}
	}



}