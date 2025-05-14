//


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


//long finalState(vector<vector<int>> operations) {
//
//    int n = operations.size() + 1;
//
//    // 차이 배열
//    vector<int> diff(100002, 0);
//    // 차이 배열에 값 저장
//    for (int i = 0; i < n - 1; ++i)
//    {
//        int start = operations[i][0];
//        int end = operations[i][1];
//
//        diff[start] += 1;
//        // 끝도 포함
//        if (end + 1 <= 100000)
//        {
//            diff[end + 1] -= 1;
//        }
//    }
//
//
//    // 값 계산 
//    int sum = 0;
//    // 결과
//    long result = 0;
//    for (int i = 1; i <= 100000; ++i)
//    {
//        sum += diff[i];
//        // 누적합이 홀수이면 켜짐
//        if (sum % 2 == 1)
//        {
//            result += i;
//        }
//    }
//
//    return result;
//}


//vector<int> sortBinaryNumbers(vector<vector<int>> bitArrays) {
//
//    int n = bitArrays.size();
//    int m = bitArrays[0].size();
//
//    // bitArray의 값 10진수로 저장
//    // first 가 decimal 값, second가 index
//    vector<pair<int, int>> decimal;
//    for (int i = 0; i < n; ++i)
//    {
//        int deci = 0;
//        for (int j = 0; j < m; ++j)
//        {
//            deci += pow(2, bitArrays[i][j]);
//        }
//        decimal.push_back({ deci, i });
//    }
//
//    // 이 값을 정렬
//    sort(decimal.begin(), decimal.end(), greater<pair<int, int>>());
//
//    // 그 값을 결과값으로 반환
//    vector<int> result;
//    for (int i = 0; i < decimal.size(); ++i)
//    {
//        result.push_back(decimal[i].second);
//    }
//    return result;
//
//}

long teamFormation(vector<int> score, int team_size, int k) {

    int n = score.size();

    priority_queue<int> leftpq;
    priority_queue<int> rightpq;
    // pq에 값 넣기
    int left = 0;
    int right = n - 1;
    for (int i = 0; i < k; ++i)
    {
        if (i < n && left <= right)
        {
            leftpq.push(score[i]);
            ++left;
        }
    }
    for (int i = 0; i < k; ++i)
    {
        if (i < n && left <= right)
        {
            rightpq.push(score[(n - 1) - i]);
            --right;
        }
    }
    // score 전체 값 저장
    long sum = 0;
    //for (int i = 0; i < n; ++i)
    //{
    //    sum += score[i];
    //}


    // n - team_size 만큼 반복

    for (int i = 0; i < team_size; ++i)
    {
        // 왼쪽 pq와 오른쪽 pq 값 비교후 최대값쪽 pop 
        int lval = 0;
        int rval = 0;
        if(!leftpq.empty()) lval = leftpq.top();
        if(!rightpq.empty()) rval = rightpq.top();

        int bigger = 0;
        if (lval > rval || (lval == rval))
        {
            bigger = lval;
            leftpq.pop();
            // pq에 값 넣어줌
            if (left <= right)
            {
                leftpq.push(score[left++]);
            }
        }
        else if (rval > lval)
        {
            bigger = rval;
            rightpq.pop();
            // pq에 값 넣어줌
            if (left <= right)
            {
                rightpq.push(score[right--]);
            }
        }


        // score의 전체 합 중에 빼줌 
        //sum -= bigger;
        sum+= bigger;

    }

    // 반환 
    return sum;

}

int findBreakDuration(int n, int k, int t, vector<int> start, vector<int> finish) {

    // 앞 뒤 휴식 시간
    int maxBreak = max(start[0], t - finish[n - 1]);

    // 모든 break
    vector<int> breaks;

    for (int i = 0; i < n - 1; ++i)
    {
        int b = start[i + 1] - finish[i];
        if (b > 0) breaks.push_back(b);
    }


    // 정렬
    sort(breaks.begin(), breaks.end(), greater<int>());

    int m = min(k, (int)breaks.size());
    for (int i = 0; i < m; ++i)
    {
        maxBreak = max(maxBreak, breaks[i]);
    }

    return maxBreak;
}

bool isBitGreater(vector<int> a, vector<int> b)
{
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());

    int i = 0, j = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] > b[i]) return true;
        if (a[i] < b[i]) return false;
        ++i; ++j;
    }

    // 같으면 더 긴쪽이 크다
    return a.size() > b.size();
}

vector<vector<int>> gbitArrays;

bool isGreater(int i, int j)
{
    return isBitGreater(gbitArrays[i], gbitArrays[j]);
}

vector<int> sortBinaryNumbers(vector<vector<int>> bitArrays) {

    int n = bitArrays.size();

    // 복사
    copy(bitArrays.begin(), bitArrays.end(), back_inserter(gbitArrays));

    vector<int> index(n);
    for (int i = 0; i < n; ++i) index[i] = i;

    sort(index.begin(), index.end(), isGreater);

    return index;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    //int n, m;
    //cin >> n >> m;
    // 입력
    //vector<vector<int>> input(n, vector<int>(m));

    //for (int i = 0; i < n; ++i)
    //{
    //    for (int j = 0; j < m; ++j)
    //    {
    //       cin >> input[i][j];
    //    }
    //}
    //vector<int>result = sortBinaryNumbers(input);
    //for (int i = 0; i < result.size(); ++i)
    //{
    //    cout <<result[i] << endl;
    //}

    int n;
    cin >> n;
    vector<int> score;
    for (int i = 0; i < n; ++i)
    {
        int v;
        cin >> v;
        score.push_back(v);
    }
    int tsize, k;
    cin >> tsize;
    cin >> k;

    cout << teamFormation(score, tsize, k);

}