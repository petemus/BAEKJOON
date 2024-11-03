//



#include <iostream>
#include <vector>
using namespace std;

// 10m
// �Ź� ���� ���ſ� ���ݸ� ���ָ� �ּ����� �ʳ�?
// ���ݸ� ���� 10�� d�� 200�� ��ü �ݺ��ϸ� �ð� �ʰ�
// -> �켱���� ť


#include <queue>



int findMinWeight(vector<int> weights, int d) {

    // �켱���� ť ����, �Ҵ�
    priority_queue<int> pq(weights.begin(), weights.end());

    // day ��ŭ �ݺ�
    for (int i = 0; i < d; i++)
    {
        int eat = pq.top();
        pq.pop();

        // ������ �Ծ��ֱ�
        eat -= (eat / 2);
        // �ٽ� �־��ֱ�
        pq.push(eat);
    }

    // ��ü ���� ���
    int weightSum = 0;
    while (!pq.empty())
    {
        weightSum += pq.top();
        pq.pop();
    }

    return weightSum;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


}