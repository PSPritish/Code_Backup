#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"

void solve()
{
    int q;
    cin >> q;
    set<int> a, b;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        if (x == 1)
        {
            a.insert(y);
            b.erase(y);
            if (a.find(y + 1) == a.end())
            {
                b.insert(y + 1);
            }
            else
            {
                auto it = b.find(y + 1);
                if (it != b.end())
                {
                    b.erase(it);
                }
            }
        }
        else
        {
            if (a.find(y) == a.end())
            {
                cout << y << endl;
                continue;
            }
            auto it = b.lower_bound(y);
            if (it == b.end())
            {
                cout << y << endl;
            }
            else
                cout << *it << endl;
        }
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