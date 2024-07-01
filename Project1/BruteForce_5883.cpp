// Brute Force > ������ 9s (5883��)
// Ǯ�� �ð� :
// 1) Brute Force : 1000 * 100�� -> �ִ� 10��(�ʰ�)
// 2) Brute Force (n * n)��ŭ Ž�� 1000 * 1000 -> 100��
// + ����� �������� �ʴ� ���� ���µ�
// + map�� ����ؼ� 

#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int arr[1000];
	vector<int> gb;
	for (int i = 0; i < n; i++)
	{	
		int t;
		cin >> t;
		arr[i] = t;
		gb.push_back(t);
	}

	// Brute Force 
	// ������� �ϳ��� �����ϰ� �ش� ���� �����ϰ� ���� ���̰� �� ���� ���� üũ
	// arr[i]�� ������ �뷮
	// ���� ���̰� �� ���� ���� üũ
	
	// O(nlogn)�ɸ�
	sort(gb.begin(), gb.end());
	gb.erase(unique(gb.begin(), gb.end()), gb.end());

	int maxLen = 0;
	for (int i = 0; i < gb.size(); i++)
	{
		int len = 0;
		int nowVal = 0; // ���ϴ� �뷮�� 0�� ���� ���� ���� ���� 
		for (int j = 0; j < n; j++)
		{
			if (arr[j] == gb[i]) continue;

			if (nowVal == arr[j]) ++len;
			else
			{
				// �ٸ� ���ڰ� ������ �ִ� ���̶� �� + �ʱ�ȭ
				if (len > maxLen) maxLen = len;
				nowVal = arr[j];
				len = 1;
			}
		}
		// �ٸ� ���ڰ� ������ �ʰ� ������ �ִ밪 Ȯ�� �����ֹǷ� ���������� �ѹ� �� üũ
		if (len > maxLen) maxLen = len;
	}

	cout << maxLen;
}