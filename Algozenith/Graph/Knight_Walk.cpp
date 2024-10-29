#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
using state = pair<int, int>;

int n, sx, sy, fx, fy;
vector<vector<int>> r;
vector<vector<int>> visited;

int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {1, -1, 2, -2, 2, -2, -1, 1};

bool valid(int x, int y)
{
    if (x <= 0 || x > n || y <= 0 || y > n || visited[x][y] != -1)
        return false;
    return true;
}

vector<state> neighbours(state node)
{
    vector<state> n;
    for (int i = 0; i < 8; i++)
    {
        int nx = node.first + dx[i], ny = node.second + dy[i];
        if (valid(nx, ny))
            n.push_back(make_pair(nx, ny));
    }
    return n;
}

int bfs(state node)
{
    queue<state> q;
    visited[node.first][node.second] = 0;
    q.push(node);
    int ans = -1;
    while (!q.empty())
    {
        state cu_node = q.front();
        q.pop();
        int curr = visited[cu_node.first][cu_node.second];

        if (cu_node.first == fx && cu_node.second == fy)
        {
            ans = curr;
            break;
        }
        for (auto v : neighbours(cu_node))
        {
            {
                visited[v.first][v.second] = curr + 1;

                q.push(v);
            }
        }
    }
    return ans;
}

void solve()
{
    cin >> n >> sx >> sy >> fx >> fy;
    r.resize(n + 1);
    visited.assign(n + 1, vector<int>(n + 1, -1));

    cout << bfs(make_pair(sx, sy)) << endl;
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