#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
int n, m;
vector<vector<int>> r;

vector<vector<int>> visited;
vector<vector<int>> vis;
using state = pair<int, int>;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool valid(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m || r[x][y] == 1)
        return false;
    return true;
}

vector<state> neighbours(state node)
{
    vector<state> n;
    for (int i = 0; i < 4; i++)
    {
        int nx = node.first + dx[i], ny = node.second + dy[i];
        if (valid(nx, ny))
            n.push_back(make_pair(nx, ny));
    }
    return n;
}

void bfs(state node)
{
    queue<state> q;
    visited[node.first][node.second] = true;
    q.push(node);
    int s = 1;
    while (!q.empty())
    {
        state cu_node = q.front();
        q.pop();
        for (auto v : neighbours(cu_node))
        {
            if (!visited[v.first][v.second] && r[v.first][v.second] == 0)
            {
                visited[v.first][v.second] = true;
                s++;
                q.push(v);
            }
        }
    }
    // cout<<s<<endl;
    if (s == 1)
        return;

    r[node.first][node.second] = s;

    vis[node.first][node.second] = true;
    q.push(node);
    while (!q.empty())
    {
        state cu_node = q.front();
        q.pop();
        for (auto v : neighbours(cu_node))
        {
            if (!vis[v.first][v.second])
            {
                vis[v.first][v.second] = true;
                r[v.first][v.second] = s;
                q.push(v);
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    r.resize(n + 1);
    visited.assign(n + 1, vector<int>(m + 1, 0));
    vis.assign(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int temp;
            cin >> temp;
            r[i].push_back(temp);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && r[i][j] == 0)
            {

                bfs(make_pair(i, j));
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << r[i][j] << ' ';
        }
        cout << endl;
    }

    r.clear();
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int i;
    cin >> i;
    while (i--)
        solve();
}