//



#include <iostream>
#include <vector>
using namespace std;

// 10m
// 매번 가장 무거운 초콜릿 빼주면 최소이지 않나?
// 초콜릿 개수 10만 d는 200만 전체 반복하면 시간 초과
// -> 우선순위 큐


#include <queue>



int findMinWeight(vector<int> weights, int d) {

    // 우선순위 큐 생성, 할당
    priority_queue<int> pq(weights.begin(), weights.end());

    // day 만큼 반복
    for (int i = 0; i < d; i++)
    {
        int eat = pq.top();
        pq.pop();

        // 나눠서 먹어주기
        eat -= (eat / 2);
        // 다시 넣어주기
        pq.push(eat);
    }

    // 전체 무게 계산
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