#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
vector<vector<int>> grid;
vector<vector<int>> dist;
int n, m;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
void bfs(pair<int, int> src)
{
    dist.assign(n, vector<int>(m, 1e18));

    deque<pair<int, int>> q;

    q.push_front(src);
    dist[src.first][src.second] = 0;

    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop_front();
        for (int i = 0; i < 4; i++)
        {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx < 0 or xx >= n or yy < 0 or yy >= m)
                continue;
            if (grid[xx][yy] == 0)
            {
                if (dist[xx][yy] > dist[x][y])
                {
                    dist[xx][yy] = dist[x][y];
                    q.push_front({xx, yy});
                }
            }
            else if (grid[xx][yy] == 1)
            {
                for (int i = xx - 1; i <= xx + 1; i++)
                {
                    for (int j = yy - 1; j <= yy + 1; j++)
                    {
                        if (i >= 0 and i < n and j >= 0 and j < m)
                        {
                            if (dist[i][j] > dist[x][y] + 1)
                            {
                                dist[i][j] = dist[x][y] + 1;
                                q.push_back({i, j});
                            }
                        }
                    }
                }
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    grid.assign(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char ch;
            cin >> ch;
            if (ch == '#')
                grid[i][j] = 1;
        }
    }
    bfs({0, 0});
    cout << dist[n - 1][m - 1];
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int a; cin>>a; while(a--)
    solve();
}