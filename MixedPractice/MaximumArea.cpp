#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"

void solve()
{
    int w, h, n;
    cin >> h >> w >> n;
    set<int> a, b;
    multiset<int> c, d;

    a.insert(0);
    a.insert(h);
    b.insert(0);
    b.insert(w);

    c.insert(h);
    d.insert(w);
    while (n--)
    {
        char y;
        int x;
        cin >> y >> x;
        if (y == 'H')
        {
            a.insert(x);
            auto it = a.lower_bound(x);

            auto left = (it);
            auto right = (it);
            right++;
            left--;

            c.erase(c.find(*right - *left));
            c.insert(x - *left);
            c.insert(*right - x);
        }
        else
        {
            b.insert(x);
            auto it = b.lower_bound(x);

            auto left = (it);
            auto right = (it);
            right++;
            left--;

            d.erase(d.find(*right - *left));
            d.insert(x - *left);
            d.insert(*right - x);
        }
        cout << (*c.rbegin()) * (*d.rbegin()) << endl;
    }
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