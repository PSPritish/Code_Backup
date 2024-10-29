#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"
int a[55];
int dp[55][55][55];
int done[55][55];
int n, x, y, z;
int rec(int l, int r, int xx)
{ // minimum cost to merge the elements from l to r such that the final element is xx
    if (l == r)
    {
        if (a[l] == xx)
        {
            return 0;
        }
        else
            return 1e18;
    }
    
    if (done[l][r] == 1)
        return dp[l][r][xx];

    for (int i{0}; i < 50; i++)
        dp[l][r][i] = 1e18;

    for (int mid = l; mid < r; mid++)
    {
        for (int i{0}; i < 50; i++)
        {
            for (int j{0}; j < 50; j++)
            {
                dp[l][r][((i * x + j * y + z) % 50)] = min(dp[l][r][((i * x + j * y + z) % 50)], rec(l, mid, i) + rec(mid + 1, r, j) + i * j);
            }
        }
    }
    done[l][r] = 1;
    return dp[l][r][xx];
}
void solve()
{
    memset(dp, -1, sizeof(dp));
    cin >> n >> x >> y >> z;
    for (int i{0}; i < n; i++)
    {
        cin >> a[i];
    }

    int ans = 1e18;
    for (int i{0}; i < 50; i++)
    {
        ans = min(ans, rec(0, n - 1, i));
    }
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;

    while (t--)
        solve();
}