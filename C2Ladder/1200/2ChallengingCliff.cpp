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
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if (n == 2)
    {
        cout << a[0] << " " << a[1] << endl;
        return;
    }
    int pos = -1, diff = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        int temp = abs(a[i] - a[i - 1]);
        if (temp < diff)
        {
            diff = temp;
            pos = i;
        }
    }

    for (int i = pos; i < n; i++)
    {
        cout << a[i] << " ";
    }
    for (int i = 0; i < pos; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
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