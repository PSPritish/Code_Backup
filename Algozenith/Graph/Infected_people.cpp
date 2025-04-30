#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
using state = pair<int, int>;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void solve()
{
    int n, m;
    cin >> n >> m;
    int dist[n + 10][m + 10];
    bool valid[n + 10][m + 10];

    queue<pair<int, int>> inf;
    vector<pair<int, int>> uninf;

    memset(dist, -1, sizeof(dist));

    memset(valid, true, sizeof(valid));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int temp;
            cin >> temp;
            if (temp == 1)
            {
                uninf.push_back({i, j});
            }
            else if (temp == 2)
            {
                dist[i][j] = 0;
                inf.push({i, j});
            }
            else if (temp == 0)
            {
                valid[i][j] = false;
            }
        }
    }

    while (!inf.empty())
    {
        auto x = inf.front().first, y = inf.front().second;
        inf.pop();
        for (int i = 0; i < 4; i++)
        {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx < 0 || xx >= n || yy < 0 || yy >= m)
                continue;
            else if (dist[xx][yy] == -1 && valid[xx][yy])
            {
                inf.push({xx, yy});
                dist[xx][yy] = 1 + dist[x][y];
            }
        }
    }
    int ans = 0;
    bool flag = true;
    for (auto v : uninf)
    {
        auto x = v.first, y = v.second;
        if (dist[x][y] == -1)
        {
            flag = false;
        }
        else
        {
            ans = max(ans, dist[x][y]);
        }
    }

    if (flag)
        cout << ans << endl;
    else
        cout << -1 << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int i; cin>>i; while(i--)
    solve();
}