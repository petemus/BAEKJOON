// ���ڿ�, ��Ž > ���ڿ�(1120��)
// Ǯ�� �ð� : 8 20


// ��Ž ? ��Ʈ��ŷ? -> �� �� ������ ��� ����� �� üũ �� �ּ� ��� => X ���ʿ�
// ���� ���ڿ��� �״���̹Ƿ� �� ���ڿ��� �̵��ϸ鼭 �ּ��� ���� ã���� �� 


#include <iostream>
using namespace std;


int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// a ���� <= b ����
	string a, b;
	cin >> a >> b;

	int minDis = 50;
	for (int i = 0; i <= (b.size() - a.size()); ++i)
	{
		int dis = 0;
		for (int j = 0; j < a.size(); ++j)
		{
			if (a[j] != b[i + j])
			{
				++dis;
			}
		}

		// �ּڰ� ��
		if(minDis > dis) minDis = dis;

	}

	cout << minDis;


}