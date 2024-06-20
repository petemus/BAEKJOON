// Priority Queue > 절대값 힙 (11286번)
// 풀이 시간 : 15 m
// 우선 순위 큐에 compare 함수(함수가 아니라 구조체, 구조체 안의 연산자 오버로딩 정의)를 따로 만들어서 구현(compare 함수는 절대값기준으로 넣기)
// compare : 절대값 기준으로 넣고 절대값이 같으면 크기가 작은 값이 우선 순위

// 우선 순위 큐 : 모든 원소 중에서 가장 큰 값이 top이 되도록(우선 순위를 가지는) 큐
// - 항상 정렬을 유지하는 컨테이너라고 생각하면 될듯  
// - 내부적으로는 heap 자료구조 사용 
// - 헤더 파일 : #include <queue>
// - pair 구조체 삽입시 first 기준으로 정렬 
// - 선언 방법 : priority_queue<'자료형', '구현체'(vector<자료형>을 일반적으로 사용) , '비교연산자'> 이름 ;
// - 비교 연산자로 greater<int>를 사용하면 오름차순
// - 기본 or less<int> 사용하면 내림차순 
// - 직접 비교 연산자를 정의해서 사용할 수 있음 


#include <iostream>
#include <queue>
using namespace std;

struct compare
{
	bool operator()(int a, int b)
	{
		if (abs(a) == abs(b))
		{
			// 작은 값이 우선순위가 높아야할 때(오름차순), > 사용
			// 큰 값이 우선순위가 높아야할 때(내림차순), < 사용
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
			// 값 출력, 큐에서 제거
			// 비어 있으면 0 출력

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