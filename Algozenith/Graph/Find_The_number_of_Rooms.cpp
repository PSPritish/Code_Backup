#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
vector<string> g;
bool visited[1010][1010];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int n, m;
bool check(int x, int y)
{
    if (x <= 0 || x > n || y < 0 || y > m)
        return false;
    return true;
}

void dfs(int x, int y)
{
    visited[x][y] = true;
    for (int i = 0; i < 5; i++)
    {
        int npx = dx[i] + x, npy = dy[i] + y;
        if (check(npx, npy) && g[npx][npy] == '.')
        {
            if (!visited[npx][npy])
            {
                dfs(npx, npy);
            }
        }
    }
}

void solve()
{

    cin >> n >> m;

    g.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> g[i];

    memset(visited, false, sizeof(visited));

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j] && g[i][j] == '.')
            {
                ans++;
                dfs(i, j);
            }
        }
    }
    cout << ans << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int i; cin>>i; while(i--)
    solve();
}