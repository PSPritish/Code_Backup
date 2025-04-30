#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"
int n, m;
vector<int> adj[100100];
int vis[100100];
void bfs(int i){
	queue<int> q;
	q.push(i);
	vis[i] = 1;
	while(!q.empty())
	{
		int node = q.front();
		q.pop();
		vis[node] = 1;
		for(auto &v: adj[node]){
			if(vis[v] != 1){
				q.push(v);
			}
		}
	}
}
void solve() 
{
    cin>>n>>m;
    for(int i{0};i < m;i++){
    	int a, b; cin>>a>>b;
    	adj[b].push_back(a);
    	adj[a].push_back(b);
    }
    for(int i{0};i <= n;i++)vis[i] = -1;

    vector<int> ans;
	int nroad{0};
    for(int i{1};i <= n;i++){
    	if(vis[i] != 1){
    		bfs(i);
    		nroad++;
    		ans.push_back(i);
    	}
    }
    if(nroad == 1){
    	cout<<0<<endl;
    	return;
    }
    cout<<nroad - 1<<endl;
    for(int i{1};i < ans.size();i++){
    	cout<<ans[0]<<' '<<ans[i]<<endl;
    }

}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    //int t; cin >> t; while(t--)
    solve();        
}