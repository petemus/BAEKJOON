// �� ������ > �� ���� (2230��)
// ���� �۰� ���� ���̸� ���Ѵ� 
// ! O(n^2) ��: �ð� �ʰ�
//	���̰� ���� �۾ƾ��� -> ������ �� ���·� �� �ڷκ��� �ٿ����鼭 ���� ���� ���� ���ϱ�

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	// ����
	sort(arr.begin(), arr.end());

	// �� �� ���� ��ġ���� �����ؼ� ���̰� ���� �Ÿ� ã�� ����
	int start = 0, end = 1;

	// 20���� �ִ�
	int min = 2000000000;
	while (start < end && end < n)
	{
		int dis = arr[end] - arr[start];
		
		if (dis < m)
		{
			// m���� ������ end�� ����
			++end;
		}
		else
		{
			// m���� ũ�ų� ������ start�� ���� 
			// �̶� �ּҰ����� Ȯ��
			if(dis < min) min = dis;

			// !!! �̰� �߿� 
			// �ٵ� ���� start�� ���������� end�� ������ end�� ���� 
			if(end - start == 1) ++end;
			else ++start;
		}

	}

	cout << min;



}