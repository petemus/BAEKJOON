// dp > ��ģ�� (2193��)
// ��ģ�� ����
// 1�϶� ���� ���� 1�̸� �ȵǴ� ���� 

// !��Ģ ã�� -> �� ������ ���ڰ� 0�̸� ������ ���� �� �ִ� �� 1, 0
// -> �������� 1�̸� ���� ���ڴ� ������ 0
// => �������� 0�� ��ģ�� ��, �������� 1�� ��ģ�� ��
// =>  0[i] = 0[i-1] + 1[i-1] :: 1[i] = 0[i-1]
// ! ���� ������ ��� �������� -> ���� �������� �ſ� Ŀ����.


#include <iostream>
#include <memory.h>
using namespace std;

// ! ���� ������ ��� �������� -> ���� �������� �ſ� Ŀ����.

// index ��° ���� 0�� ��ģ�� ��
long long memo0[91];
// index ��° ���� 1�� ��ģ�� ��
long long memo1[91];



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	memset(memo0, -1, 91 * sizeof(int));
	memset(memo1, -1, 91 * sizeof(int));


	// �ʱⰪ
	memo0[1] = 0;
	memo1[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		// ���� ����
		memo0[i] = memo0[i - 1] + memo1[i - 1];
		memo1[i] = memo0[i - 1];
 	}

	// ��ü�� �� �� ��
	cout << memo0[n] + memo1[n];

	
}