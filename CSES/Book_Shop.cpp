#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> book(n), page(n);

    for (int i = 0; i < n; i++)
        cin >> book[i];
    for (int i = 0; i < n; i++)
        cin >> page[i];

    vector<int> dp(x + 1, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = x; j >= book[i]; j--) // Reverse to avoid overwriting
        {
            dp[j] = max(dp[j], dp[j - book[i]] + page[i]);
        }
    }

    cout << dp[x] << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    while (t--)
        solve();
}
