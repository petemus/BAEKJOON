// Priority Queue > ���밪 �� (11286��)
// Ǯ�� �ð� : 15 m
// �켱 ���� ť�� compare �Լ�(�Լ��� �ƴ϶� ����ü, ����ü ���� ������ �����ε� ����)�� ���� ���� ����(compare �Լ��� ���밪�������� �ֱ�)
// compare : ���밪 �������� �ְ� ���밪�� ������ ũ�Ⱑ ���� ���� �켱 ����

// �켱 ���� ť : ��� ���� �߿��� ���� ū ���� top�� �ǵ���(�켱 ������ ������) ť
// - �׻� ������ �����ϴ� �����̳ʶ�� �����ϸ� �ɵ�  
// - ���������δ� heap �ڷᱸ�� ��� 
// - ��� ���� : #include <queue>
// - pair ����ü ���Խ� first �������� ���� 
// - ���� ��� : priority_queue<'�ڷ���', '����ü'(vector<�ڷ���>�� �Ϲ������� ���) , '�񱳿�����'> �̸� ;
// - �� �����ڷ� greater<int>�� ����ϸ� ��������
// - �⺻ or less<int> ����ϸ� �������� 
// - ���� �� �����ڸ� �����ؼ� ����� �� ���� 


#include <iostream>
#include <queue>
using namespace std;

struct compare
{
	bool operator()(int a, int b)
	{
		if (abs(a) == abs(b))
		{
			// ���� ���� �켱������ ���ƾ��� ��(��������), > ���
			// ū ���� �켱������ ���ƾ��� ��(��������), < ���
			return a > b;
		}
		else return abs(a) > abs(b);
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	priority_queue<int, vector<int>, compare> pq;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;

		if (input == 0)
		{
			// �� ���, ť���� ����
			// ��� ������ 0 ���

			if (pq.empty()) cout << 0 << '\n';
			else
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		// push
		else pq.push(input);
	}


}