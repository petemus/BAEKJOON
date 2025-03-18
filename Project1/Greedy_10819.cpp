// ��Ž, ��Ʈ��ŷ, �׸���?(�׸��� �ƴѰ�?)  > ���̸� �ִ�� (10819��)
// Ǯ�� �ð� : 


// ���� ���� i ��°���� i-1, i+1 ��°�� ���� �� ���� �ִ븦 ���ؾ��� 
// n�� 8�̿��� (�ִ� 8! -> 4�� �����ؼ� ��Ž �����ҵ�)


// �׸��� ->  ���� �� ���� �� �ֵ鳢���� ���̰� �ִ��� 


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	vector<int> arr;

	// input
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		arr.push_back(num);
	}

	// ����
	sort(arr.begin(), arr.end());

	// ���� �� ������ ����

	int left = 0;
	int right = n -1;

	// �ִ�
	int difSum = arr[right] - arr[left];

	while (left < right)
	{
		if (left + 1 == right - 1)
		{
			// Ȧ���̸�, �� ���̰� ū �ַ� ����
			difSum += (arr[right] - arr[right -1]) > (arr[left + 1] - arr[left]) ?
			arr[right] - arr[right - 1] : arr[left + 1] - arr[left];
		}
		else
		{
			// �ƴϸ� �� �����ֱ� 
			difSum += arr[right - 1] - arr[left];
			difSum += arr[right] - arr[left + 1];
		}

		++left;
		--right;
	}

	cout << difSum;


}