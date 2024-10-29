#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"
const int N = 1100;

int g[N][N];
int vis[N][N];
int back[N][N];
int n, m;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
void bfs(int a, int b){
    
    queue<pair<int,int>> q;
    q.push({a,b});
    vis[a][b] = 0;

    while(!q.empty()){
        auto c = q.front();
        q.pop();
        for(int i{0};i < 4;i++){
            int xx = c.first + dx[i], yy = c.second + dy[i];
            if(xx >= 0 and xx < n and yy >= 0 and yy < m and g[xx][yy] == 1 and vis[xx][yy] > (vis[c.first][c.second] + 1)){
                q.push({xx, yy});
                vis[xx][yy] = vis[c.first][c.second] + 1;
                back[xx][yy] = i;
            }
        }

    }
}
void solve()
{    
    cin>>n>>m;
    pair<int, int> st, ed;
    for(int i{0};i < n;i++){
        for(int j{0};j < m;j++){
            char temp; cin>>temp;
            g[i][j] = (temp == '#')? 0:1;
            if(temp == 'A')st = {i, j};
            if(temp == 'B')ed = {i, j};
        }
    }
    for(int i{0};i < n;i++){
        for(int j{0};j < m;j++){
            vis[i][j] = 1e9;
            back[i][j] = -1;
        }
    }
   
    bfs(st.first, st.second);
    string s{};

    int i = ed.first, j = ed.second;
    if(vis[i][j] == 1e9){
    	cout<<"NO"<<endl;
    	return;
    }
    else{
    	cout<<"YES"<<endl;
    	cout<<vis[i][j]<<endl;
    }
    while(i != st.first or j != st.second)
    {
    	int te = back[i][j];
    	//s += (te == 0)? 'R':(te == 1)?'L':(te == 2)?'D':'U';
    	// cout<<te<<endl;
    	if(te == 0){
    		i--;
    		s+='D';
    	}
    	else if(te == 1)
    	{
    		i++;
    		s += 'U';
    	}
    	else if(te == 2)
    	{
    		j++;
    		s += 'L';
    	}
    	else {
    		j--;
    		s += 'R';
    	}
    }
    reverse(s.begin(), s.end());
    cout<<s<<endl;


}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //int a; cin>>a; while(a--)
    solve();
}