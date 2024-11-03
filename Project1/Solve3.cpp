//


// n^2시 시간 너무 오래 걸림 


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long sumVips(vector<int> score, int guilder_count, int k) {

    // 제거된 기여도 합
    int vipSum = 0;

    // guilder_count 만큼 반복
    for (int i = 0; i < guilder_count; i++)
    {
        // 범위 넘어가면 전체 
        int scoresize = score.size();

        vector<int> front(score.begin(), score.begin() + min(k, scoresize));
        vector<int> back(score.end() - min(k, scoresize), score.end());

        // max_element() 함수 사용 
        vector<int>::iterator frontMaxIter = max_element(front.begin(), front.end());
        vector<int>::iterator backMaxIter = max_element(back.begin(), back.end());

        // 두 값 비교 후 삭제
        // ! score에서 다시 값을 찾은 후 삭제
        if (*frontMaxIter > *backMaxIter)
        {
            score.erase(find(score.begin(), score.end(), *frontMaxIter));
            vipSum += *frontMaxIter;
        }
        else if (*frontMaxIter < *backMaxIter)
        {
            score.erase(find(score.begin(), score.end(), *backMaxIter));
            vipSum += *backMaxIter;
        }
        else
        {
            // 같으면 앞의 인덱스에서 삭제
            if (find(score.begin(), score.end(), *frontMaxIter) < find(score.begin(), score.end(), *backMaxIter))
            {
                score.erase(find(score.begin(), score.end(), *frontMaxIter));
                vipSum += *frontMaxIter;
            }
            else
            {
                score.erase(find(score.begin(), score.end(), *backMaxIter));
                vipSum += *backMaxIter;
            }

        }


    }

    // 제거된 기여도 합
    return vipSum;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    vector<int> score = {8, 21, 8, 15, 5, 30, 21};

    cout << sumVips(score, 2, 3);
}