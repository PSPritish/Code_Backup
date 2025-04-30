#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
using state = pair<int, int>;
int n, m;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int g[1100][1100];
int cost[1100][1100];

void bfs01(state sc)
{

    deque<state> dq;

    dq.push_back(sc);
    cost[sc.first][sc.second] = 0;

    while (!dq.empty())
    {
        state node = dq.front();
        dq.pop_front();
        int x = node.first, y = node.second;

        for (int i = 0; i < 4; i++)
        {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx < 0 or xx >= n or yy < 0 or yy >= m)
                continue;

            int c = !(i + 1 == g[x][y]);

            if (cost[xx][yy] > cost[x][y] + c)
            {
                cost[xx][yy] = cost[x][y] + c;
                if (c)
                    dq.push_back({xx, yy});
                else
                    dq.push_front({xx, yy});
            }
        }
    }
}
void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cost[i][j] = 1e9;
        }
    }
    bfs01({0, 0});

    cout << cost[n - 1][m - 1] << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int i; cin>>i; while(i--)
    solve();
}