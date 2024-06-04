// Priority Queue > ī�� �����ϱ� (1715��)
// Ǯ�� �ð� : 10m
// ���� ������ ���ϰ� ���ϸ� ���� �ʳ� -> !���� ���� �ٽ� ���� �Ǿ�� �� => �� �켱���� ť ����ϸ� ����

#include <iostream>	
#include <queue>
using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	// �ߴ��� �ɾ�ΰ� pq ���θ� Ȯ���غ��� ���ĵǾ� ���� ���� ���� ������ Ȯ���� �� ���� 
	// why...
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++)
	{
		int cards;
		cin >> cards;
		pq.push(cards);
	}

	int result = 0;
	while (pq.size() > 1)
	{
		int comp1 = pq.top(); pq.pop();
		int comp2 = pq.top(); pq.pop();

		result += comp1 + comp2;
		pq.push(comp1 + comp2);
	}

	cout << result;
}