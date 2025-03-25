// Author: P S Pritish
#include <bits/stdc++.h>
using namespace std;

// Author: Karan Kumar Sethi

using namespace std;

#define endl "\n"
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repa(i, a, n) for (ll i = a; i < n; i++)
#define repab(i, a, n, b) for (ll i = a; i < n; i = i + b)
#define mod 1000000007
#define pb push_back
const ll N = 2e5 + 20, inf = 1e9;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    bool isZeropresent = false;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            isZeropresent = true;
            break;
        }
    }
    if (!isZeropresent)
    {
        cout << 1 << endl;
        cout << 1 << " " << n << endl;
        return;
    }
    if (a[0] == 0 && a[n - 1] == 0)
    {
        cout << 3 << endl;
        cout << 3 << " " << n << endl;
        cout << 1 << " " << 2 << endl;

        cout << 1 << " " << 2 << endl;
        // cout<<n<<endl;
        return;
    }
    else
    {
        if (a[0] != 0)
        {
            cout << 2 << endl;
            cout << 2 << " " << n << endl;
            cout << 1 << " " << 2 << endl;
            return;
        }
        else
        {
            cout << 2 << endl;
            cout << 1 << " " << n - 1 << endl;
            cout << 1 << " " << 2 << endl;
            return;
        }
    }
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