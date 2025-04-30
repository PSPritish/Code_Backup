#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"
const int mod = 1e9 + 7;
// int a[10000];
// int dp[1100][1100];
// vector<int> backtrack[1100][1100];
// int n;
// int cnt[1100];
// // solving length of LIS using recursion
// int rec(int level, int prev)
// {
//     if (level > n)
//         return 0;

//     int &ans = dp[level][prev];
//     if (ans != -1)
//         return ans;

//     int leave = rec(level + 1, prev);
//     if (prev == 0 or a[level] > a[prev])
//     {
//         int take = 1 + rec(level + 1, level);
//         ans = max(leave, take);
//     }

//     return ans;
// }
void solve()
{
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int dp[n + 1];
    int cnt[n + 1];//stores the number of ways to get the LIS at ith index with length dp[i]
    for(int i{1}; i <= n; i++){
        dp[i] = 1;
        cnt[i] = 1;
    }
    
    // memset(dp, -1, sizeof(dp));
    // memset(cnt, 0, sizeof(cnt));
    // int ans = rec(1, 0);
    // // cout << ans << endl;

    // cout<<endl;
    // // cout<<ans<<endl;
    int maxi = 1;
    for (int i{1}; i <= n; i++)
    {
        for (int k{1}; k < i; k++)
        {
            if(a[i] > a[k]){
                if(dp[i] < dp[k] + 1)
                {
                    dp[i] = dp[k] + 1;
                    cnt[i] = cnt[k];
                }
                else if(dp[i] == dp[k] + 1){
                    cnt[i] += cnt[k];
                }              
            }  
            maxi = max(maxi, dp[i]);        
        }
    }
    int nox = 0;
    for(int i{1}; i <= n; i++){
        nox += (dp[i] == maxi)?cnt[i]:0;
    }
    cout<<nox<<endl;
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