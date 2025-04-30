#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"

void solve()
{
    int n; cin>>n;
    int ans = 1;
    for(int i{0};i < 64;i++){
        if((n >> i) & 1){
            ans *= 2;
        }
    }
    cout<<n + 1 - ans<<" "<<ans<<endl;
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