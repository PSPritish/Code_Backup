#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"
// determine weather there exist a solution for the equation ax + by = c
void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    int temp = __gcd(a, b);

    if (c % temp != 0)
    {
        cout << "No";
    }
    else
        cout << "Yes";
    cout << '\n';
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