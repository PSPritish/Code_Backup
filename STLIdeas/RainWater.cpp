#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    int h[n];
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    int lm[n], rm[n];
    int maxi = -1;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, h[i]);
        lm[i] = maxi;
    }
    maxi = -1;
    for (int i = n - 1; i >= 0; i--)
    {
        maxi = max(maxi, h[i]);
        rm[i] = maxi;
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res += min(rm[i], lm[i]) - h[i];
    }
    cout << res << endl;
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