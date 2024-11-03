//



#include <iostream>
#include <vector>
using namespace std;



#include <memory.h>

// 5 33m
// ���� �� �����ϴ� �κ� ������ ã�� (��ü ũ�� - ���� �� �����ϴ� �κ� ������ ũ��) - 1�� ���� 
// ! ���� �� �����ϴ� �κ� ������ �� ã�� 
// DP


// ������ �迭
int memo0[100002];
// ���� �迭
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
        // i�� �������Ҷ� memo
        if (memo1[i - 1] > memo0[i - 1])
        {
            memo0[i] = memo1[i - 1];
            outNum = inNum;
        }
        else
        {
            memo0[i] = memo0[i - 1];
        }

        // i�� �����Ҷ� memo -> ũ�� üũ
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
                // �Ѵ� ������ memo1�� ������ �� ���� 
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
            // ����
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