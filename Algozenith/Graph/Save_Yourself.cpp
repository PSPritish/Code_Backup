#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
using state = pair<int, int>;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void solve()
{
    int N = 1100;
    int n, m;
    cin >> n >> m;

    bool pos[N][N];
    int distM[N][N];
    int distA[N][N];

    queue<state> posM;
    queue<state> posA;

    memset(pos, false, sizeof(pos));
    memset(distM, -1, sizeof(distM));
    memset(distA, -1, sizeof(distA));

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            pos[i][j] = true;

            if (s[j] == '#')
            {
                pos[i][j] = false;
            }
            else if (s[j] == 'M')
            {
                posM.push({i, j});
                distM[i][j] = 0;
            }
            else if (s[j] == 'A')
            {
                posA.push({i, j});
                distA[i][j] = 0;
            }
        }
    }

    while (!posM.empty())
    {
        auto it = posM.front();
        int x = it.first, y = it.second;
        posM.pop();
        for (int i = 0; i < 4; i++)
        {
            auto xx = x + dx[i], yy = y + dy[i];
            if (xx < 0 || xx >= n || yy < 0 || yy >= m)
                continue;
            else if (pos[xx][yy] && distM[xx][yy] == -1)
            {
                distM[xx][yy] = 1 + distM[x][y];
                posM.push(make_pair(xx, yy));
            }
        }
    }

    while (!posA.empty())
    {
        auto it = posA.front();
        int x = it.first, y = it.second;
        posA.pop();
        for (int i = 0; i < 4; i++)
        {
            auto xx = x + dx[i], yy = y + dy[i];
            if (xx < 0 || xx >= n || yy < 0 || yy >= m)
                continue;
            else if (pos[xx][yy] && distA[xx][yy] == -1)
            {
                distA[xx][yy] = 1 + distA[x][y];
                posA.push({xx, yy});
            }
        }
    }
    int ans = INT_MAX;
    int flag = -1;
    for (int i = 0; i < n; i++)
    {
        if (pos[i][0] && distA[i][0] >= 0 && (distA[i][0] < distM[i][0] || distM[i][0] == -1))
        {
            flag = 0;
            ans = min(ans, distA[i][0]);
        }

        if (pos[i][m - 1] && distA[i][m - 1] >= 0 && (distA[i][m - 1] < distM[i][m - 1] || distM[i][m - 1] == -1))
        {
            flag = 0;
            ans = min(ans, distA[i][m - 1]);
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (pos[0][i] && distA[0][i] >= 0 && (distA[0][i] < distM[0][i] || distM[0][i] == -1))
        {
            flag = 0;
            ans = min(ans, distA[0][i]);
        }
        if (pos[n - 1][i] && distA[n - 1][i] >= 0 && (distA[n - 1][i] < distM[n - 1][i] || distM[n - 1][i] == -1))
        {
            flag = 0;
            ans = min(ans, distA[n - 1][i]);
        }
    }

    if (flag != -1)
    {
        cout << "YES" << endl;
        cout << ans << endl;
    }
    else
        cout << "NO\n";
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int i; cin>>i; while(i--)
    solve();
}