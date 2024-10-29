#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
string a, b;
int n, m;
int dp[1510][1510];
int rec(int i, int j)
{
    // prune

    // base
    if (i == n and j == m)
        return 0;
    // cache check;
    if (dp[i][j] != -1)
        return dp[i][j];
    // comput
    int ans = 1e18;
    if (i < n)
    {
        ans = min({ans, rec(i + 1, j) + 1, rec(i + 1, j + 1) + 1});
    }
    if (j < m)
    {
        ans = min({ans, rec(i, j + 1) + 1, rec(i + 1, j + 1) + 1});
    }
    if (i < n and j < m and a[i] == b[j])
        ans = min(ans, rec(i + 1, j + 1));
    // return
    return dp[i][j] = ans;
}
void solve()
{
    cin >> a >> b;
    memset(dp, -1, sizeof(dp));
    n = a.length();
    m = b.length();
    cout << rec(0, 0) << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int a; cin>>a; while(a--)
    solve();
}