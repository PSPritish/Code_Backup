#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"

void solve()
{
    int n; cin>>n;
    int a[n];
    for(int i{0};i < n; i++){
        cin>>a[i];
    }
    int ans = INT_MIN, mn = 1, mx = 1;
    for(int i{0};i < n;i++){
        int t = mx;
        mx = max({mx*a[i], a[i], mn*a[i]});
        mn = min({t*a[i], a[i], mn*a[i]});
        ans = max({ans, mx});
    }
    cout<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;

    while (t--)
        solve();
}