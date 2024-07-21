// BFS > 단지번호붙이기(2667번)


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n;
int map[25][25] = { 0, };
bool isVisited[25][25] = { false, };
// direct arr
int dirX[4] = { 0, 0, 1, -1 };
int dirY[4] = { 1, -1, 0, 0 };

// 아파트 단지 세어줌
int BFS(int a, int b)
{
    queue<pair<int, int>> q;
    q.push({ a, b });
    isVisited[a][b] = true;

    int cnt = 1;
    while (!q.empty())
    {
        pair<int, int> apt = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nY = apt.first + dirY[i];
            int nX = apt.second + dirX[i];
            if (nY >= 0 && nY < n && nX >= 0 && nX < n)
            {
                if (!isVisited[nY][nX] && map[nY][nX] == 1)
                {
                    // 아파트 단지이고 방문하지 않았을때만
                    ++cnt;
                    isVisited[nY][nX] = true;
                    q.push({ nY, nX });
                }
            }
        }
    }

    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) map[i][j] = s[j] - '0';
    }

    int aptNum = 0;
    vector<int> apts;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // 아파트 단지이고 방문하지 않았으면 BFS
            if (map[i][j] == 1 && !isVisited[i][j])
            {
                ++aptNum;
                apts.push_back(BFS(i, j));
            }
        }
    }

    sort(apts.begin(), apts.end());
    // 정렬
    cout << aptNum << '\n';
    for (int i = 0; i < apts.size(); i++) cout << apts[i] << '\n';

}