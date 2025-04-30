#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"

void solve()
{
    int n;
    cin >> n;
    vector<int> a, b, c;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    for(int i{0};i < n;i++){
        int x;
        cin>>x;
        b.push_back(x);
    }
    for(int i{0};i < n;i++){
        c.push_back(a[i] - b[i]);
    }
    int cnt = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        if (c[i] <= 0)
        {
            if (lower_bound(c.begin(), c.end(), -c[i] + 1LL) - c.begin() != n)
            {
                cnt += n - (lower_bound(c.begin(), c.end(), -c[i] + 1LL) - c.begin());
            }
        }
        else
        {
            cnt += n - (i + 1);
        }
        
    }cout << cnt << endl;
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