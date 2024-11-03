//


// n^2�� �ð� �ʹ� ���� �ɸ� 


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long sumVips(vector<int> score, int guilder_count, int k) {

    // ���ŵ� �⿩�� ��
    int vipSum = 0;

    // guilder_count ��ŭ �ݺ�
    for (int i = 0; i < guilder_count; i++)
    {
        // ���� �Ѿ�� ��ü 
        int scoresize = score.size();

        vector<int> front(score.begin(), score.begin() + min(k, scoresize));
        vector<int> back(score.end() - min(k, scoresize), score.end());

        // max_element() �Լ� ��� 
        vector<int>::iterator frontMaxIter = max_element(front.begin(), front.end());
        vector<int>::iterator backMaxIter = max_element(back.begin(), back.end());

        // �� �� �� �� ����
        // ! score���� �ٽ� ���� ã�� �� ����
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
            // ������ ���� �ε������� ����
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

    // ���ŵ� �⿩�� ��
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