#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (auto &v : arr)
        cin >> v;

    function<int(int, int, int)> rec = [&](int player, int l, int r) -> int
    {
        if (l == r)
        {
            return ((player) ? arr[l] : 0);
        }
        return max(rec(1 - player, l + 1, r) + arr[l], rec(1 - player, l, r - 1) + arr[r]);
    };
    cout << max(rec(0, 0 + 1, n - 1) + arr[0], rec(0, 0, n - 2) + arr[n - 1]);
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