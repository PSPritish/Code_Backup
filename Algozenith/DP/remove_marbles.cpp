#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"
int dp[100][100][100];
int a[100];
int rec(int i, int j, int x){
    if(i > j){
        return 0;
    }
    int &ans = dp[i][j][x];
    if(ans != -1)return ans;

    ans = rec(i + 1, j, 0) + (x + 1)*(x + 1);
    for(int mid = i + 1;mid <= j;mid++){
        if(a[mid] == a[i]){
            ans = max({ans, rec(i + 1, mid - 1, 0) + rec(mid, j, x + 1)});
        }
    }
    return ans;
}
void solve()
{
    memset(dp, -1, sizeof(dp));
    int n; cin>>n;
    for(int i{0};i < n;i++)cin>>a[i];
    int ans = rec(0, n - 1, 0);
    cout<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;

    while (t--)
        solve();
}