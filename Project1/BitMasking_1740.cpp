// Bitmasking > �ŵ�����(1740��)
// Ǯ�� �ð� :

// point1> 1, 3, 9, 27.. ��  ���� �ٸ�(0,1�� ǥ�� ����-> ��Ʈ����ŷ) 3�� �ŵ��������� ������ ǥ��
// point2> N �� ũ�� �ǹ� 5000�� -> int ���� �ִ� ���� 21���̹Ƿ� long long ���̿����ҵ� 
// point3> ���� > N��°��ŭ �����ְ� -> �� ���� 3�� �ŵ��������� ��ȯ 

// ! �ð� �ʰ� -> ��Ʈ �ڸ�����ŭ ����� ��
// ! Ʋ�� -> result�� ���� long long�� ������ �Ѿ�� �� �ƴ϶� << ������ ����
//			!1 << i�� int ���� (31��Ʈ)�� �ʰ��ϸ� �����÷��� �߻���

#include <iostream>
#include <cmath>	// pow() -> pow�� double �� ��ȯ ���� 
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	long long n;
	cin >> n;

	// ��Ʈ����ŷ
	unsigned long long p = 0;

	// N ��ŭ ��Ʈ�� �����ְ�
	// �� ���� 3�� �ŵ��������� ��ȯ
	p += n;

	long long result = 0;
	long long seq = 1;
	// ��Ʈ �ڸ�����ŭ ��� 
	for (int i = 0; i < 64; ++i)
	{
		// ��Ʈ ���� ������ ������
		// !! 1 << i�� int ���� (31��Ʈ)�� �ʰ��ϸ� �����÷��� �߻���
		// !! pow ���� ��ȯ���� double�̿��� ������ ���� ����
		if (p & (1LL << i))
		{
			//result += pow(3, i);
			result += seq;
		}
		seq *= 3;
	}

	cout << result;

}