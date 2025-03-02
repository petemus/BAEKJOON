// �׸��� > �� �ٷ� ����(1138��)
// Ǯ�� �ð� : 40m


// ���ʿ� �ڱ⺸�� ū ����� ���� �� 
// point1> �ڱ� ���ڸ� ���κ��� �� ��ġ �� �� ���� 
// point2> ������ ���� ���� ��ġ�� ���� �ּ���ġ�� ���ذ��鼭 �� �ڸ� ã�� 



#include <iostream>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// input
	int n;
	cin >> n;

	// ���� �� ������� Ű
	int line[12] = {0, };
	int leftTall[12];

	for (int i = 0; i < n; ++i)
	{
		cin >> leftTall[i];
	}


	// Ű ���� ����� ������� line ����
	for (int i = 0; i < n; ++i)
	{
		// �ּ� ��ġ -> ���ʿ� ū ����� �� (leftTall)
		// �ִ� ��ġ -> ���ʿ� ū ����� �� + �ڱ⺸�� ���� ��� �� (Max ũ�� üũ)
		// int minIdx = leftTall[i];
		// int maxIdx = ((leftTall[i] + i) < (n-1)) ? leftTall[i] + i : n - 1;

		int nowIdx = leftTall[i];

		// ��� ����üũ�ؼ� minIdx �Ǵ� maxIdx �������� ���
		for (int j = 0; j < n; ++j)
		{
			if (line[j] > 0)
			{
				// ���� ������ minIdx�� ��
				if(j <= nowIdx)
				{
					++nowIdx;
				}
			}
		}

		// ��ġ ã���� �װ��� �� �־���
		line[nowIdx] = i + 1;
	}




	// output
	for (int i = 0; i < n; ++i)
	{
		cout << line[i] << ' ';
	}




}