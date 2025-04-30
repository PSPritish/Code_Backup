#include <bits/stdc++.h>
using namespace std;
void solve()
{
    long long n;
    cin >> n;
    long long a[n];
    long long cnt[20];
    memset(cnt, 0, sizeof(cnt));

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        for (int j = 0; j <= 31; j++)
        {
            if (a[i] & (1LL << j))
                cnt[j]++;
        }
    }
    // for (int i = 0; i < 20; ++i)
    // {
    //     cout<<cnt[i]<<' ';
    // }
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        long long temp = 0;
        for (int j = 0; j < 20; j++)
        {
            if (cnt[j])
            {
                temp |= (1 << j);
                cnt[j]--;
            }
        }

        ans += temp * temp;
    }
    cout << ans << '\n';
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}