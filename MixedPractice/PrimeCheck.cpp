#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"

void solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << "NO" << endl;
        return;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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