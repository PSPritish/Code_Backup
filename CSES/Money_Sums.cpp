#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"

void solve()
{
    int n;
    cin >> n;
    int money[n];
    for (int &v : money)
        cin >> v;
    int maxm = n * 1000;
    vector<vector<bool>> dp(n + 1, vector<bool>(maxm + 1, false));
    dp[0][0] = true;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= maxm; j++)
        {
            dp[i][j] = dp[i - 1][j];
            int left = j - money[i - 1];
            if (left >= 0 and dp[i - 1][left] == true)
                dp[i][j] = true;
        }
    }
    vector<int> possible;
    for (int i = 1; i <= maxm; i++)
    {
        if (dp[n][i])
            possible.push_back(i);
    }
    cout << possible.size() << endl;
    for (auto &v : possible)
        cout << v << " ";
}

signed main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    //  cin >> t;

    while (t--)
        solve();
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
}