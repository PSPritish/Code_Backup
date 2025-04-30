#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
int n, arr[505];
int dp[505][505];
int rec(int l, int r)
{
    if (l == r)
        return 0;

    if (dp[l][r] != -1)
        return dp[l][r];

    int tot = 0, sum = 0;
    for (int i = l; i <= r; i++)
    {
        tot += arr[i];
    }
    int ans = 1e18;
    for (int mid = l; mid < r; mid++)
    {
        sum += arr[mid];
        ans = min(ans, rec(l, mid) + rec(mid + 1, r) + (sum % 100) * ((tot - sum) % 100));
    }
    return dp[l][r] = ans;
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    memset(dp, -1, sizeof(dp));
    cout << rec(0, n - 1) << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int a; cin>>a; while(a--)
    solve();
}