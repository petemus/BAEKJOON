// Two pointer > 부분합(1806번)
// 풀이 시간 : 35m
// 연속된 수들의 부분합 중에 그 합이 s이상 인 것 중에 최소인것 

// ! 연속됐으므로 Start ---- end 가 부분합이라고 할때
// start의 증가는 (수가 다 양수이므로) 부분합이 무조건 감소
// end의 증가는 부분합이 증가
// => s 이상이면 start 감소, s이하이면 end 증가

#include <iostream>
#include <vector>
using namespace std;

// 최대 길이
#define MAXLENGTH 100000

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// input
	int n, s;
	cin >> n >> s;

	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	// 투 포인터
	int start = 0, end = 0;

	// 최소 길이 (최대 길이 10만)
	int minLen = MAXLENGTH;
	int subSum = arr[start];
	while (start <= end && end < n)
	{
		// 부분합을 줄이거나 늘어가면서 체크
		if (subSum < s)
		{
			// s 보다 작으면 end 늘림 (end가 == n이 되버리면 out of range)
			// end 증가 -> 더함
			++end;
			if(end < n) subSum += arr[end];
		}
		else
		{
			// 최소 길이인지 확인 
			// s 이상이면 start 증가, subsum 감소
			int len = end - start + 1;
			if(len < minLen) minLen = len;

			// start 증가 -> 빼줌
			// 항상 배열 인덱스를 증가 혹은 감소할때는 범위에 넘어갈 수 있는 경우를 고려해라
			// start랑 end가 같으면 minLen은 1 -> 더 이상 안해줘도 됨
			if(start == end) break;
			else subSum -= arr[start++];
		}
	}

	// output
	// ! 만일 그러한 합을 만드는 것이 불가능하면 0을 출력 
	if(minLen == MAXLENGTH) cout << 0;
	else cout << minLen;

}