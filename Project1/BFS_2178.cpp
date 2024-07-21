// BFS > 미로탐색(2178번)

#include <iostream>
#include <queue>
using namespace std;

int n, m;
int maze[100][100];
bool isVisited[100][100] = { false, };
int dirY[4] = { -1, 1, 0, 0 };
int dirX[4] = { 0, 0, -1, 1 };

int BFS(int y, int x)
{
    queue<pair<pair<int, int>, int>> q;
    isVisited[y][x] = true;
    q.push({ { y, x }, 1 });

    int minMove = 0;

    while (!q.empty())
    {
        pair<pair<int, int>, int> now = q.front();
        q.pop();

        // 종료조건
        if (now.first.first == n - 1 && now.first.second == m - 1) return now.second;

        for (int i = 0; i < 4; i++)
        {
            int nY = now.first.first + dirY[i];
            int nX = now.first.second + dirX[i];
            if (nY >= 0 && nY < n && nX >= 0 && nX < m)
            {
                if (!isVisited[nY][nX] && maze[nY][nX] == 1)
                {
                    q.push({ { nY, nX }, now.second + 1 });
                    isVisited[nY][nX] = true;
                }
            }
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    string tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        for (int j = 0; j < m; j++) maze[i][j] = (tmp[j] - '0');
    }

    // BFS
    cout << BFS(0, 0);

}