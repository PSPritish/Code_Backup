#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
using state = pair<int, int>;
int n, k;
vector<vector<int>> grid;
vector<vector<int>> visited;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int cnt;
int bfs(state st_node, int count)
{
    queue<state> q;
    q.push(st_node);
    int color = grid[st_node.first][st_node.second];
    visited[st_node.first][st_node.second] = 1;

    while (!q.empty())
    {
        auto it = q.front();
        int x = it.first, y = it.second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx < 0 || xx >= n || yy < 0 || yy >= 10)
                continue;
            else if (!visited[xx][yy] && grid[xx][yy] == color)
            {
                q.push(make_pair(xx, yy));
                count++;
                visited[xx][yy] = 1;
            }
        }
    }

    return count;
}
void gravity()
{ // function to keep all the zeros above the coloumn
    for (int i = 0; i < 10; i++)
    {
        int p = n - 1;
        for (int j = n - 1; j >= 0; j--)
        {
            if (grid[j][i] != 0)
            {
                swap(grid[j][i], grid[p][i]);
                p--;
            }
        }
    }
}
void dfs_del(int x, int y, int color)
{

    grid[x][y] = 0;
    for (int i = 0; i < 4; i++)
    {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx < 0 || xx >= n || yy < 0 || yy >= 10)
            continue;
        else if (grid[xx][yy] == color)
        {
            dfs_del(xx, yy, color);
        }
    }
}
void dfs(int x, int y, int color)
{
    cnt++;
    visited[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx < 0 || xx >= n || yy < 0 || yy >= 10)
            continue;
        else if (!visited[xx][yy] && grid[xx][yy] == color)
        {
            dfs(xx, yy, color);
        }
    }
}

void solve()
{
    cin >> n >> k;
    grid.resize(n);

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < 10; j++)
        {
            int temp = s[j] - '0';
            grid[i].push_back(temp);
        }
    }
    int flag = 1;
    while (flag)
    {
        flag = 0;
        visited.assign(n, vector<int>(10, 0));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < 10; j++)
            {
                int comp_size = 0;
                if (visited[i][j] == 0 && grid[i][j] != 0)
                {
                    comp_size = bfs(make_pair(i, j), 1);

                    if (comp_size >= k)
                    {
                        dfs_del(i, j, grid[i][j]);
                        flag = 1;
                    }
                }

                // cnt = 0;
                // if(visited[i][j] == 0 && grid[i][j] != 0){
                //    dfs( i,j ,grid[i][j]);
                //    if(cnt >= k){
                //     dfs_del( i,j ,grid[i][j]);
                //     flag = 1;
                // }

                // }
            }
        }
        gravity();
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int i; cin>>i; while(i--)
    solve();
}
// 6 3 0000000000 0000000300 0054000300 1054502230 2211122220 1111111223