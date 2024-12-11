// ��Ʈ ����ŷ > ���� (11723��)
//
// ���� �ȿ� ���ԵǾ� �ִ� ������ ������ ��Ʈ�� ǥ��


// & : AND ����
// | : OR ����
// ~ : Not ����
// ^ : NOR ���� (�ٸ��� true / ������ false) 


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
	int s = 0;			// s�� ���� 
	while (m--)
	{
		cin >> command;
		int x; 
		if (command == "add")
		{
			cin >> x;
			s |= (1 << (x - 1)); // 0010000.. �̷��� �� ��Ʈ���� ����(0�� ���) �״��(1�� ���)
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