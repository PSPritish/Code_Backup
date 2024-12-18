#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"
int binpow(int a, int b, int p)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = ((ans % p) * (a % p)) % p;
        }
        b >>= 1;
        a = (a * a) % p;
    }
    return ans;
}
void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (c != 0 and b == 0)
    {
        cout << 1 << endl;
        return;
    }
    if (a == 0 or a % d == 0)
    {
        cout << 0 << endl;
        return;
    }
    int ans = binpow(a, binpow(b, c, d - 1), d);
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;

    while (t--)
        solve();
}