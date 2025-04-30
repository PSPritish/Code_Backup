// Author: P S Pritish
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"
constexpr int mod = 1e9 + 7;
constexpr int inf = 1e18 + 1;
int maxDesksInRow(int m, int L)
{
    if (L >= m)
        return m;
    int Y_max = (m + L) / (L + 1); // maximum possible groups
    int y0 = (m + 1) / (L + 1);    // floor of (m+1)/(L+1)
    int y1 = ((m + 1) % (L + 1) == 0) ? y0 : y0 + 1;

    int cand0 = 0, cand1 = 0;
    if (y0 >= 1 && y0 <= Y_max)
        cand0 = min(m - y0 + 1, y0 * L);
    if (y1 >= 1 && y1 <= Y_max)
        cand1 = min(m - y1 + 1, y1 * L);
    return max(cand0, cand1);
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    int hi = m, lo = 1, ans = hi;
    while (hi >= lo)
    {
        int mid = lo + (hi - lo) / 2;
        int capacity = n * maxDesksInRow(m, mid);
        if (capacity >= k)
        {
            ans = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    cout << ans << endl;
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