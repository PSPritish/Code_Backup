#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
using state = pair<int, int>;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int n;

vector<string> plot;
vector<vector<bool>> visited;

int bfs(state node)
{
    queue<state> q;
    q.push(node);
    int cnt = 0;
    while (!q.empty())
    {
        auto it = q.front();
        auto x = it.first, y = it.second;
        visited[x][y] = true;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            auto xx = x + dx[i], yy = y + dy[i];
            if (xx < 0 || xx >= n || yy < 0 || yy >= n || plot[xx][yy] == '.')
                continue;
            else if (plot[xx][yy] == '#' && !visited[xx][yy])
            {
                q.push(make_pair(xx, yy));
            }
        }
        cnt++;
    }
    cout << cnt << endl;
    return cnt;
}
int perimeter;
vector<state> ans;
void dfs(state node, int &count)
{

    auto x = node.first, y = node.second;
    count++;

    visited[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int xx = x + dx[i], yy = y + dy[i];

        if (xx >= 0 && xx < n && yy >= 0 && yy < n && plot[xx][yy] == '#' && !visited[xx][yy])
        {

            dfs({xx, yy}, count);
        }
        else if (xx == n || xx == -1 || yy == -1 || yy == n)
        {
            perimeter++;
        }
        else if (plot[xx][yy] == '.')
            perimeter++;
    }
}

void solve()
{
    cin >> n;
    plot.resize(n);
    visited.assign(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        plot[i] = s;
    }

    int count;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (plot[i][j] == '#' && !visited[i][j])
            {
                int count = 0;
                perimeter = 0;
                dfs(make_pair(i, j), count);

                //  ans = max(ans,bfs(make_pair(i,j)));
                // int temp = bfs(make_pair(i,j));

                ans.push_back(make_pair(-1 * count, perimeter));
            }
        }
    }

    //  for(int i = 0;i < n;i++)
    // {
    //     for(int j = 0;j < n;j++)
    //     {
    //         cout<<plot[i][j]<<'\t';
    //     }
    //     cout<<endl;
    // }

    sort(ans.begin(), ans.end());

    cout << -ans[0].first << ' ' << ans[0].second << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int i; cin>>i; while(i--)
    solve();
}