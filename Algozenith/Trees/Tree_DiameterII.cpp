#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"

int depth[200200], parent[200200];
vector<int> adj[200200];
int n;
int dia;
int cnt;
int x;
void dfs(int v, int par, int d)
{
    depth[v] = d;
    parent[v] = par;
    for (auto to : adj[v])
    {
        if (to != par)
        {
            dfs(to, v, d + 1);
        }
    }
}

void dfs2(int v, int par, int d)
{
    if (d == x)
        cnt++;
    for (auto to : adj[v])
    {
        if (to != par)
        {
            dfs2(to, v, d + 1);
        }
    }
}

void solve()
{

    cin >> n;
    if (n == 1)
    {
        cout << "1" << endl;
        return;
    }
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int maxch = 1;
    dfs(1, 0, 0);
    for (int i = 2; i <= n; i++)
    {
        if (depth[i] > depth[maxch])
            maxch = i;
    }
    dfs(maxch, 0, 0);
    maxch = 1;
    for (int i = 2; i <= n; i++)
    {
        if (depth[i] > depth[maxch])
            maxch = i;
    }
    dia = depth[maxch];
    int center = maxch;

    for (int i = 0; i < dia / 2; i++)
    {
        center = parent[center];
    }

    if (dia % 2 != 0)
    {
        x = dia / 2;
        int c1 = center, c2;
        c2 = parent[center];
        int u, v;
        cnt = 0;
        dfs2(c1, c2, 0);
        u = cnt;
        cnt = 0;
        dfs2(c2, c1, 0);
        v = cnt;
        cnt = 0;
        cout << v * u;
    }

    else
    {
        int ans = 0;
        x = dia / 2 - 1;
        vector<int> val;
        for (auto to : adj[center])
        {
            cnt = 0;
            dfs2(to, center, 0);
            if (cnt != 0)
                val.push_back(cnt);
        }
        int len = val.size();
        int sum = 0;
        for (int i = 0; i < len; i++)
        {
            sum += val[i];
        }
        for (int i = 0; i < len - 1; i++)
        {
            sum -= val[i];
            ans += (val[i] * sum);
        }
        cout << ans;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int a; cin>>a; while(a--)
    solve();
}