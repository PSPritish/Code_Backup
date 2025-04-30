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
    long long x;
    cin >> n >> x;
    vector<long long> skills(n);
    for (int i = 0; i < n; i++)
    {
        cin >> skills[i];
    }
    sort(skills.rbegin(), skills.rend());

    int teams = 0, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt++;
        if (skills[i] * cnt >= x)
        {
            teams++;
            cnt = 0;
        }
    }
    cout << teams << "\n";
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