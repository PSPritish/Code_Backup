#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void solve()
{

    int64_t n;
    cin >> n;

    for (int64_t i = 63; i >= 0; i--)
    {
        if (n & (1LL << i))
        {
            cout << 1;
        }
        else
            cout << 0;
    }
    cout << endl;
    if (n == 0)
    {
        cout << -1 << endl;
    }

    else
        cout << (63 - __builtin_clzll(n)) << endl;

    if (n == 0)
    {
        cout << -1 << endl;
    }

    else
        cout << __builtin_ctzll(n) << endl;

    if ((__builtin_popcount(n) == 1) && n != 0 && n != 1)
        cout << 1 << endl;
    else
        cout << 0 << endl;

    if (n == 0)
    {
        cout << -1 << endl;
    }
    else
        cout << (1LL << __builtin_ctzll(n)) << endl;
    int64_t temp = __builtin_clzll(n - 1);
    // cout<<temp;
    if (n <= 1)
        cout << 2 << endl;

    else
        cout << (1LL << (64 - temp)) << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a;
    cin >> a;
    while (a--)
        solve();
}