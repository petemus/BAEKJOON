// ��Ʈ ����ŷ, ��Ʈ��ŷ, ��Ž > �����̰� ���� ���ִ� ����(2961��)
// ! ��Ž base�� ������, ��͸� ����ϴ� �������� ��Ʈ ����ŷ�� ����ϸ鼭 �ݺ������� ó�� ����
// Ǯ�� �ð� : 40m....

// ��� ���� �ִ� 10 => 1023���� ����� �� 
// ��� ����� �� 2^N - 1(0�� �ȵǹǷ�) 


#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<pair<int,int>> flavors;
	for (int i = 0; i < n; ++i)
	{
		int sour, bitter;
		cin >> sour >> bitter;
		flavors.push_back({sour, bitter});
	}

	// ��Ž 
	// 1 ~ 2^n -1 ���� Ȯ�� (..01 ~ (1 << n))
	// i�� �� �����
	// �� �� ����� �ϳ��� Ȯ���ϸ鼭 ���
	int minDis = 1000000000;
	for (int i = 1; i < (1 << n); ++i)
	{
		// i�� �� ���� Ȯ���ϸ鼭 �� ���ϱ�
		int sourSum = 1;
		int bitterSum = 0;
		for (int j = 0; j < n; ++j)
		{
			if (i & (1 << j))
			{
				// �ش� ���ᰡ ������ �� ���
				sourSum *= flavors[j].first;
				bitterSum += flavors[j].second;
			}
		}
		// ��� �� ���ϸ� �ּڰ� ��
		int dis = abs(sourSum - bitterSum);
		if(dis < minDis) minDis = dis;
	}

	cout << minDis;

}