#include <bits/stdc++.h>
using namespace std;
#define int long long int

vector<int> subset(vector<int> a)
{
    vector<int> sum;
    int n = (int)a.size();
    for (int i = 0; i < 1 << n; i++)
    {
        int temp = 0;
        for (int j = 0; j < n; j++)
        {
            if ((i >> j) & 1)
                temp += a[j];
        }
        sum.push_back(temp);
    }
    sort(sum.begin(), sum.end());
    return sum;
}

void solve()
{
    int n, target;
    cin >> n >> target;
    vector<int> a[2];
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        a[i & 1].push_back(temp);
    }
    auto s1 = subset(a[0]);
    auto s2 = subset(a[1]);
    int ans = 0;
    for (auto v : s1)
    {
        ans += upper_bound(s2.begin(), s2.end(), target - v) - s2.begin();
    }
    cout << ans << '\n';
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