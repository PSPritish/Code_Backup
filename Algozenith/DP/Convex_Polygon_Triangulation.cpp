#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

int n;
vector<vector<ll>> dp;
vector<ll> a;
ll rec(int i, int j)
{
    if (abs(j - i) == 1)
        return 0;
    auto &ans = dp[i][j];
    if (ans != -1)
        return ans;
    ans = 1e18;
    for (int k = i + 1; k <= j - 1; k++)
        ans = min(ans, a[i] * a[k] * a[j] + rec(i, k) + rec(k, j));
    return ans;
}
ll minTriangulation(vector<ll> &v)
{
    n = v.size();
    a = v;
    dp.assign(n + 1, vector<ll>(n + 1, -1));
    return rec(0, n - 1);
}
void solve()
{
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    auto ans = minTriangulation(v);
    cout << ans << endl;
    assert(ans > 0);
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    // int i = 1;
    cin >> t;
    while (t--)
    {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}
