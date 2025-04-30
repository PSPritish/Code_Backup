#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0;i < n;i++){
        cin >> a[i];
        a[i] -= i;
        }
    map<int, int> mp;
    int ans = 0;
    for(int i = 0;i < n;i++){
        ans += mp[a[i]];
        mp[a[i]]++;
    }
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