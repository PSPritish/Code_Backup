#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
int n;
vector<int> adj[2002000];
int subtsz[20002000];
void dfs(int v,int par){
    subtsz[v] = 1;
    for(auto to: adj[v])
    {
        if(to != par){
            dfs(to,v);
            subtsz[v] += subtsz[to];
        }
    }
}
void solve()
{
    cin>>n;
    for(int i = 1;i < n;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);
    int ans = 0;
    for(int i = 1;i <= n;i++)
    {
        ans += (n - subtsz[i])*(subtsz[i]);
    }
    cout<<ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //int a; cin>>a; while(a--)
    solve();
}