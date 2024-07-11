//��ǥ��
//�ð� ���� : 1��
//������ �䳢�� ��ǥ���� ���� ���� ������ ������ Ǳ�ϴ�.��ǥ���� �����Դϴ�.
//���� Ǯ ���� ������ ������ ���� Ǭ ���� ������ ���� ������ ������ �����鼭, ���� Ǭ ���� ������ ������ ū �� �� ���� ���� ���Դϴ�.
//���� ���, ���� 67������ Ǯ������ ���� �� 76������ Ǳ�ϴ�.
//���� Ǭ ������ ������ ���� �� ������ Ǯ ������ ������ ����ϴ� ���α׷��� �ۼ��ϼ���

// category : BruteForce 
// Ǯ�� �ð� : 30m

// @@
// #include <string> : stoi() : string -> integer
// #include <string> : to_string() : integer -> string 



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string input;
	cin >> input;
	int n = stoi(input);

	// nums�� �ִ� ���� 6��
	vector<int> nums;
	for (int i = 0; i < input.size(); i++)
	{
		int num = input[i] - '0';
		nums.push_back(num);
	}

	// ���� ������ ����� ���� ����
	sort(nums.begin(), nums.end());
	
	int result = 0;
	// BruteForce 
	for (int i = 1; i <= 999999; i++)
	{
		// �Է°����� ū�� Ȯ��
		// ���� Ǭ ���� ������ ���� ������ ������ Ȯ�� 
		result = i;
		if (result > n)
		{
			vector<int> arr;
			string s = to_string(result);
			for (int j = 0; j < s.size(); j++)
			{
				arr.push_back(s[j] - '0');
			}
			sort(arr.begin(), arr.end());
			// arr�� nums�� ������ Ȯ��
			if (arr == nums) break;
		}
	}

	cout << result;
}