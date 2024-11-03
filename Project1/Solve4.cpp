//



#include <iostream>
#include <vector>
using namespace std;



#include <memory.h>

// 5 33m
// 가장 긴 증가하는 부분 수열을 찾고 (전체 크기 - 가장 긴 증가하는 부분 수열의 크기) - 1이 정답 
// ! 가장 긴 증가하는 부분 수열의 수 찾기 
// DP


// 미포함 배열
int memo0[100002];
// 포함 배열
int memo1[100002];



int minDeletions(vector<int> arr) {

    memset(memo0, -1, sizeof(int) * 100002);
    memset(memo1, -1, sizeof(int) * 100002);


    int inNum = arr[0];
    int outNum = 0;

    memo1[0] = 1;
    memo0[0] = 0;

    for (int i = 1; i < arr.size(); i++)
    {
        // i를 미포함할때 memo
        if (memo1[i - 1] > memo0[i - 1])
        {
            memo0[i] = memo1[i - 1];
            outNum = inNum;
        }
        else
        {
            memo0[i] = memo0[i - 1];
        }

        // i를 포함할때 memo -> 크기 체크
        if (inNum < arr[i])
        {
            if (outNum < arr[i])
            {
                memo1[i] = max(memo0[i - 1], memo1[i - 1]) + 1;
            }
            else
            {
                memo1[i] = memo1[i - 1] + 1;
            }
            inNum = arr[i];
        }
        else
        {
            if (outNum < arr[i])
            {
                memo1[i] = memo0[i - 1] + 1;
                inNum = arr[i];
            }
            else
            {
                // 둘다 작으면 memo1은 포함할 수 없음 
                memo1[i] = memo0[i];
            }
        }

    }

    int longNum = max(memo0[arr.size() - 1], memo1[arr.size() - 1]);

    return (arr.size() - longNum - 1);

}

int memo[100002];

int minDeletions(vector<int> arr) {


    int max = 0;
    // n^2
    for (int i = 1; i < arr.size(); i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            // 이전
            if (arr[j] < arr[i])
            {
                memo[i] = std::max(memo[j] + 1, memo[i]);
            }
        }
        if (memo[i] > max) max = memo[i];
    }

    return (arr.size() - max - 1);

}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    vector<int> arr = {1, 2, 6, 4, 3};

    cout << minDeletions(arr);

}