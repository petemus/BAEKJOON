// �������� ī�� ����
// # �� ������ 
// 3������ �� ī���� ���� t�� �Ѿ�� �ȵǴ� ��
// 1) for�� 3�� ��� -> �ð� �ʰ�
// 2) Backtracking -> ���������� �ð� �ʰ� ����
// ! �ߺ��� ���� ����� �� ���� 
// ! ���� ��ü��  �����ѵ�
// ! �ߺ� ���� + ū ������ ���� ġ�� �ؼ� ����
// => �� ������ �����ε� 
// Ǯ�� �ð� : 30m

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;


//long three_numbers(int t, vector<int>& d)
//{
//	// vector, ����, 
//	sort(d.begin(), d.end());
//	// �ߺ� ���� 
//	d.erase(unique(d.begin(), d.end()), d.end());
//
//	int count = 0;
//	for (int i = d.size() - 1; i >= 2; i--)
//	{
//		int sum = d[i];
//		if(sum > t) continue;
//
//		for (int j = i - 1; j >= 1; j--)
//		{
//			sum += d[j];
//			if (sum > t)
//			{
//				sum -= d[j];
//				continue;
//			}
//
//			for (int k = j - 1; k >= 0; k--)
//			{
//				sum += d[k];
//				if (sum > t)
//				{
//					sum -= d[k];
//					continue;
//				}
//				else count++;
//
//				// back
//				sum -= d[k];
//			}
//
//			// back
//			sum -= d[j];
//		}
//	}
//	return count;
//}

long three_numbers(int t, vector<int>& d) {

	// �ߺ� ���� �� ����
	sort(d.begin(), d.end());
	d.erase(unique(d.begin(), d.end()), d.end());

	long count = 0;

	// ù ��° ���� �����ϰ�, ������ �� ���� �� �����ͷ� ã��
	for (int i = 0; i < d.size() - 2; ++i) {
		int target = t - d[i];
		int left = i + 1;
		int right = d.size() - 1;

		while (left < right) {
			int sum = d[left] + d[right];
			if (sum <= target) {
				// ������ ��� ������ ������ �߰�
				count += (right - left);
				++left;
			}
			else {
				--right;
			}
		}
	}

	return count;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t = 8;
	vector<int> d = {1, 2, 3, 4, 5};


	cout << three_numbers(t, d);

}