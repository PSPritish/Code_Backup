#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"

void solve()
{
    int n; cin>>n;
    vector<pair<int,char>> a;
    for(int i=0;i < n;i++)
    {
        int x,y; cin>>x>>y;
        a.push_back({x,'a'});
        a.push_back({y,'d'});
    }
    sort(a.begin(),a.end());
    int maxi = 0, ans = 0;
    for(auto &v: a){
        if(v.second == 'a') maxi++;
        else maxi--;
        ans = max(ans,maxi);
    }
    cout<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;

    while (t--)
        solve();
}