#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"
string s, t;
int dp[600][600];
int rec(int i, int j){
    if(i == -1)return 1e9;
    if(j == -1)return 1;

    int &ans = dp[i][j];
    if(ans != -1)return ans;

    ans = 1e9;
    int k;
    for(k = j;k >= 0;k--){
        if(s[i] == t[k]){
            break;
        }
    }
    if(k == -1){
        ans = 1;
    }
    else{
        ans = min(ans, rec(i - 1, k - 1) + 1);
        ans = min(ans, rec(i - 1, j));
    }
    return ans;
}
void solve()
{
    
    cin>>s>>t;
    memset(dp, -1, sizeof(dp));
    
    int ans = rec(s.size() - 1, t.size() - 1);
    if(ans == 1e9){
        cout<<-1<<endl;
    }
    else{
        cout<<ans<<endl;
    }
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