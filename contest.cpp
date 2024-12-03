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
    map<int, int> freq;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        freq[a[i]]++;
    }
    for (auto i : freq)
    {
        v.push_back({i.second, i.first});
    }
    sort(v.begin(), v.end());

    int ans = 0;
    for (int cnt{0}, i{0}; cnt < (n + 1) / 2 and i < v.size(); i++, cnt++)
    {
        if (v[i].first == 1)
        {
            ans += 2;
        }
        else
        {
            ans += 1;
        }
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