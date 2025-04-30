#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"
unsigned int p2[100];
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int cnt = 0;
    int x = 1;
    for (int i{0}; i < 32; i++)
    {
        unordered_map<int, int> mp;
        for (int j{0}; j < n; j++)
        {
            if (mp[p2[i] - a[j]])
            {
                cnt += mp[p2[i] - a[j]];
            }
            mp[a[j]]++;
        }
    }
    cout << cnt << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    for (int i{0}; i < 32; i++)
    {
        p2[i] = 1ULL << i;
    }
    while (t--)
        solve();
}