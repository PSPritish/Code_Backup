#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"
const int N = 1100;

int g[N][N];
int vis[N][N];
int n, m;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
void bfs(int a, int b){
    
    queue<pair<int,int>> q;
    q.push({a,b});
    vis[a][b] = 1;

    while(!q.empty()){
        auto c = q.front();
        q.pop();
        for(int i{0};i < 4;i++){
            int xx = c.first + dx[i], yy = c.second + dy[i];
            if(xx >= 0 and xx < n and yy >= 0 and yy < m and g[xx][yy] == 1 and vis[xx][yy] == -1){
                q.push({xx, yy});
                vis[xx][yy] = 1;
            }
        }

    }
}
void solve()
{    
    cin>>n>>m;
    for(int i{0};i < n;i++){
        for(int j{0};j < m;j++){
            char temp; cin>>temp;
            g[i][j] = (temp == '#')? 0:1;
        }
    }
    for(int i{0};i < n;i++){
        for(int j{0};j < m;j++){
            vis[i][j] = -1;
        }
    }
    int cnt{0};
    for(int i{0};i < n;i++){
        for(int j{0};j < m;j++){
            if(g[i][j] == 1 and vis[i][j] == -1){
                bfs(i,j);
                cnt++;
            }
        }
    }
    cout<<"hello"<<endl;
    cout<<cnt<<endl;

}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //int a; cin>>a; while(a--)
    solve();
}