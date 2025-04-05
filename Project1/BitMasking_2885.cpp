// Bitmasking > 초콜릿 식사(2885번)
// 풀이시간: 3~40m
// !! 엣지케이스 잘 확인하자


// point 1 > 비트마스킹 -> k는 초콜릿들로 구성 (ex : 6 -> 110, 12 -> 1100)
//			=> 초콜릿의 쪼개지는 수는 1의 개수와 0오른쪽에 1일 경우그 1도 더함 
//			=> 위처럼 안해도, 왼쪽 시작 지점부터 1이 오는 번째 수 (근데 이렇게 하면 0의 경우는 체크 못함)
//			=> 그래서 chocoSize의 >> 1 지점부터 찾으면 0도 체크 가능 
// Point 2 > 가장 작은 초콜릿의 크기는 어떻게 구하는가 -> k의 끝을 << 로 한칸 이동한 것과 같음 
//		-> 이 경우는 그 오른쪽이 다 0이 아닌경우에만 가능 

#include <iostream>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k;
	cin >> k;

	int chocoSize = 0;
	int divideCnt = 0;
	
	// 초콜릿 크기
	int digit = 0;
	for(int i = 31; i >= 0; --i)
	{
		// 이때의 자리의 다음 
		if (k & (1 << i))
		{
			if (k == (1 << i))
			{
				// 바로 종료해도 됨
				cout << (1 << i) << " " << 0;
				return 0;
			}
			else
			{
				chocoSize = (1 << i + 1);
			}
			digit = i;
			break;
		}
	}

	// 최소 쪼개야 하는 수
	int zeroCnt = 0;
	for (int i = digit; i >= 0; --i)
	{
		if (k & (1 << i))
		{
			// 1마주치면 1개 증가, 0이 오른쪽에 있으면 그 수만큼 증가 
			divideCnt += (zeroCnt) + 1;
			zeroCnt = 0;
		}
		else
		{
			// 0이면 zeroCnt + 1
			++zeroCnt;
		}
	}


	// *output
	cout << chocoSize << " " << divideCnt;

}