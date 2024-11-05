//  �̺� Ž�� > ���� �� �����ϴ� �κ� ���� 2(12015��)

// n �ִ� ũ�� 100�� -> O(n^2) �� �ð� �ʰ� => �̺� Ž���� ���� O(nlogn)���� �ذ��ؾ��� 

#include <iostream>
#include <vector>
#include <algorithm>			// lower_bound() -> �̺� Ž�� (�ð� ���⵵ O(logN)
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// input
	int n;
	cin >> n;

	vector<int> arr(n);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}


	// �̺� Ž���� ���� ���� �� �����ϴ� �κ� ���� ���ϱ�
	// longest increase sequence (LIS)
	vector<int> lis;

	for (int i = 0; i < n; i++)
	{
		// vector<int>::iterator ��� or auto ���
		auto neighbor = lower_bound(lis.begin(), lis.end(), arr[i]);
		if (neighbor == lis.end())
		{
			// ã�� ���ϸ� push
			lis.push_back(arr[i]);
		}
		else
		{
			// ã���� �ش� ��ġ�� �� ���� 
			*neighbor = arr[i];
		}
	}

	// ���� ������ ���̰� lis�� ����(ũ��)
	cout << lis.size();



}