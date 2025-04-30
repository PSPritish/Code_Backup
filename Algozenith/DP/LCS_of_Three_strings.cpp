#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define endl '\n'
string a, b, c;
int dp[101][101][101];
int rec(int x, int y, int z)
{
    // pruneing

    // base case
    if (x == a.size() || y == b.size() || z == c.size())
    {
        return 0;
    }

    // cache check
    auto &ans = dp[x][y][z];
    if (ans != -1)
        return ans;
    // transition
    ans = max({rec(x + 1, y, z), rec(x, y + 1, z), rec(x, y, z + 1)});

    if (a[x] == b[y] and b[y] == c[z])
    {
        ans = max(ans, 1 + rec(x + 1, y + 1, z + 1));
    }
    // save and return
    return dp[x][y][z] = ans;
}

void solve()
{
    cin >> a >> b >> c;
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0, 0) << endl;
}

signed main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    int i = 1;
    cin >> t;
    while (t--)
    {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
}