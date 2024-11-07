// Two pointer > �κ���(1806��)
// Ǯ�� �ð� : 35m
// ���ӵ� ������ �κ��� �߿� �� ���� s�̻� �� �� �߿� �ּ��ΰ� 

// ! ���ӵ����Ƿ� Start ---- end �� �κ����̶�� �Ҷ�
// start�� ������ (���� �� ����̹Ƿ�) �κ����� ������ ����
// end�� ������ �κ����� ����
// => s �̻��̸� start ����, s�����̸� end ����

#include <iostream>
#include <vector>
using namespace std;

// �ִ� ����
#define MAXLENGTH 100000

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// input
	int n, s;
	cin >> n >> s;

	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	// �� ������
	int start = 0, end = 0;

	// �ּ� ���� (�ִ� ���� 10��)
	int minLen = MAXLENGTH;
	int subSum = arr[start];
	while (start <= end && end < n)
	{
		// �κ����� ���̰ų� �þ�鼭 üũ
		if (subSum < s)
		{
			// s ���� ������ end �ø� (end�� == n�� �ǹ����� out of range)
			// end ���� -> ����
			++end;
			if(end < n) subSum += arr[end];
		}
		else
		{
			// �ּ� �������� Ȯ�� 
			// s �̻��̸� start ����, subsum ����
			int len = end - start + 1;
			if(len < minLen) minLen = len;

			// start ���� -> ����
			// �׻� �迭 �ε����� ���� Ȥ�� �����Ҷ��� ������ �Ѿ �� �ִ� ��츦 ����ض�
			// start�� end�� ������ minLen�� 1 -> �� �̻� �����൵ ��
			if(start == end) break;
			else subSum -= arr[start++];
		}
	}

	// output
	// ! ���� �׷��� ���� ����� ���� �Ұ����ϸ� 0�� ��� 
	if(minLen == MAXLENGTH) cout << 0;
	else cout << minLen;

}