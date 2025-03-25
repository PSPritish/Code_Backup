// Author: P S Pritish
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"
constexpr int mod = 1e9 + 7;
constexpr int inf = 1e18 + 1;

void solve()
{
    int n;
    cin >> n;
    vector<int> ans;
    if (n % 2 == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        for (int i = 1; i <= n; i = i + 2)
        {
            ans.push_back(i);
        }
        for (int i = 2; i <= n; i = i + 2)
        {
            ans.push_back(i);
        }
    }
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}

signed main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    cin >> t;

    while (t--)
        solve();
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    ////cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
}