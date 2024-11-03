// 1> 
// 풀이 시간 15m 



#include <iostream>
#include <vector>
using namespace std;

// 투 포인터?
// 왼쪽 시작이랑 오른쪽 끝부터 시작
// 왼(짝) 오(홀) 둘다 다음
// 왼(홀) 오(홀) 오른쪽 크기 줄임
// 왼 (짝) 오(짝) 왼쪽 맞음 -> 왼쪽 크기 늘림림
// 왼(홀) 오(짝) 둘이 체인지, 크기 줄임임

int Moves(vector<int> arr) {

    int left = 0;
    int right = arr.size() - 1;

    int minMove = 0;
    while (left < right)
    {
        // 왼쪽 짝
        if (arr[left] % 2 == 0)
        {
            if (arr[right] % 2 == 0)
            {
                // 오른쪽 짝 -> 왼쪽 크기 늘림
                ++left;
            }
            else
            {
                // 오른쪽 홀 -> 정답, 둘다 줄임
                ++left; --right;
            }
        }
        // 왼쪽 홀
        else if (arr[left] % 2 == 1)
        {
            if (arr[right] % 2 == 0)
            {
                // 오른쪽 짝 -> 둘이 체인지, 크기 줄임, 이동 수 증가
                left++; --right;
                ++minMove;
            }
            else
            {
                // 오른쪽 홀 -> 오른쪽 정답 오른쪽 크기 줄임
                --right;
            }
        }

    }

    return minMove;

}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


}