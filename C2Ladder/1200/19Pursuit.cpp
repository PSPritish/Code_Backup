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
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end(), greater<int>());
    vector<int> b(n);
    for (int i = 0; i < n; i++)
        cin >> b[i];
    sort(b.begin(), b.end(), greater<int>());

    vector<int> pre_a, pre_b;
    pre_a.push_back(a[0]);
    pre_b.push_back(b[0]);

    for (int i = 1; i < n; i++)
    {
        pre_a.push_back(pre_a.back() + a[i]);
        pre_b.push_back(pre_b.back() + b[i]);
    }
    int ind = n - floor(n / 4.0) - 1;
    // if (pre_a[ind] > pre_b[ind])
    // {
    //     cout << 0 << endl;
    //     return;
    // }
    
    int hi = ceil(pre_b[n - 1] / 100.0), lo = ind;
    while (lo < hi)
    {
        int mid = lo + (hi - lo) / 2;
        int m = mid - floor(mid / 4.0);
        
        if (m < n)
        {
            int sum_b = pre_b[m - 1];
            int sum_a = 100 * (m + 1) + (pre_a[m] - pre_a[ind]);
            if (sum_a <= sum_b)
            {
                hi = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }
        else
        {
            int sum_b = pre_b[n - 1];
            int sum_a = 100 * (m - n + 1) + (pre_a[n - 1] - pre_a[m - n]);
            if (sum_a <= sum_b)
            {
                hi = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }
    }
    cout << hi << endl;
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