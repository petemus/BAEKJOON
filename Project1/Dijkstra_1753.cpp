// ���ͽ�Ʈ�� >  �ִ� ��� (1753)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define X first
#define Y second

// ����, ����, ���� ����
int v, e, st;
// {���, ���� ��ȣ}
vector<pair<int, int>> adj[20005];
const int INF = 0x3f3f3f3f;
int d[20005]; // �ִ� �Ÿ� ���̺�

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // �Է�
    cin >> v >> e >> st;
    fill(d, d + v + 1, INF);
    while (e--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ w,v });
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    d[st] = 0;
    // �켱���� ť�� (0, ������) �߰�
    pq.push({ d[st],st });
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop(); // {���, ���� ��ȣ}    

        // �Ÿ��� d�� �ִ� ���� �ٸ� ��� �Ѿ
        if (d[cur.Y] != cur.X) continue;

        for (auto nxt : adj[cur.Y]) {
            if (d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
            // cur�� ���İ��� ���� �� ���� ���� ���� ���
            // d[nxt.Y]�� �����ϰ� �켱���� ť�� (�Ÿ�, nxt.Y)�� �߰�
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({ d[nxt.Y],nxt.Y });
        }
    }

    for (int i = 1; i <= v; i++) {
        if (d[i] == INF) cout << "INF\n";
        else cout << d[i] << "\n";
    }


}