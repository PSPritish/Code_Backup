#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
vector<vector<int>> t;

void solve()
{
    int n;
    cin >> n;
    t.resize(n + 1);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        t[a].push_back(b);
        t[b].push_back(a);
    }
    int ans = 0;
    for (auto v : t)
    {
        ans = max((int)v.size(), ans);
    }

    cout << ans + 1 << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int i; cin>>i; while(i--)
    solve();
}