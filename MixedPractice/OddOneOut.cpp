#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
void solve()
{
    int ans = 0;
    int n;
    cin >> n;
    while (n--)
    {
        int temp;
        cin >> temp;
        ans ^= temp;
    }
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a;
    cin >> a;
    while (a--)
        solve();
}