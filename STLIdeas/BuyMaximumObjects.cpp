#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i{0}; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i{1}; i < n; i++)
    {
        a[i] += a[i - 1];
    }
    while (q--)
    {
        int x;
        cin >> x;
        int cnt = upper_bound(a.begin(), a.end(), x) - a.begin();
        cout << cnt << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;

    while (t--)
        solve();
}