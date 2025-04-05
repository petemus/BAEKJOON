// Bitmasking > ���ݸ� �Ļ�(2885��)
// Ǯ�̽ð�: 3~40m
// !! �������̽� �� Ȯ������


// point 1 > ��Ʈ����ŷ -> k�� ���ݸ���� ���� (ex : 6 -> 110, 12 -> 1100)
//			=> ���ݸ��� �ɰ����� ���� 1�� ������ 0�����ʿ� 1�� ���� 1�� ���� 
//			=> ��ó�� ���ص�, ���� ���� �������� 1�� ���� ��° �� (�ٵ� �̷��� �ϸ� 0�� ���� üũ ����)
//			=> �׷��� chocoSize�� >> 1 �������� ã���� 0�� üũ ���� 
// Point 2 > ���� ���� ���ݸ��� ũ��� ��� ���ϴ°� -> k�� ���� << �� ��ĭ �̵��� �Ͱ� ���� 
//		-> �� ���� �� �������� �� 0�� �ƴѰ�쿡�� ���� 

#include <iostream>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k;
	cin >> k;

	int chocoSize = 0;
	int divideCnt = 0;
	
	// ���ݸ� ũ��
	int digit = 0;
	for(int i = 31; i >= 0; --i)
	{
		// �̶��� �ڸ��� ���� 
		if (k & (1 << i))
		{
			if (k == (1 << i))
			{
				// �ٷ� �����ص� ��
				cout << (1 << i) << " " << 0;
				return 0;
			}
			else
			{
				chocoSize = (1 << i + 1);
			}
			digit = i;
			break;
		}
	}

	// �ּ� �ɰ��� �ϴ� ��
	int zeroCnt = 0;
	for (int i = digit; i >= 0; --i)
	{
		if (k & (1 << i))
		{
			// 1����ġ�� 1�� ����, 0�� �����ʿ� ������ �� ����ŭ ���� 
			divideCnt += (zeroCnt) + 1;
			zeroCnt = 0;
		}
		else
		{
			// 0�̸� zeroCnt + 1
			++zeroCnt;
		}
	}


	// *output
	cout << chocoSize << " " << divideCnt;

}