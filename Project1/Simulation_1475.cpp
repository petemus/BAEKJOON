// Simulation > �� ��ȣ (1475��)
// Ǯ�� �ð� : 13m

#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	// ���ڿ� �Է� �ް�
	// ���ڿ� ���ڷ� �ɰ��� number�� ���� ������
	// �������� ���� �ִ밪 ��ŭ ���

	// number ���� ���ֱ�
	int number[10] = { 0, };
	string s;

	cin >> s;

	for (int i = 0; i < s.size(); i++)
	{
		// ���� ���� �ٲ��ֱ�
		int n = s[i] - '0';
		number[n]++;
	}

	// 6�̳� 9 �ּ�ȭ
	int result = number[6] + number[9];
	if (result % 2 == 1) result = result / 2 + 1;
	else result /= 2;
	number[6] = result; number[9] = result;

	int max = 0;
	for (int i = 0; i < 10; i++)
	{
		if (max < number[i]) max = number[i];
	}


	cout << max;




}