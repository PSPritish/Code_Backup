#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    set<int> st[26];
    int q;
    cin >> q;
    for (int i{0}; i < n; i++)
    {
        st[s[i] - 'a'].insert(i);
    }
    while (q--)
    {
        int c;
        cin >> c;
        if (c == 1)
        {
            int x; char y;
            cin >> x >> y;
            for (int i{0}; i < 26; i++)
            {
                auto it = st[i].find(x - 1);
                if (it != st[i].end())
                {
                    st[i].erase(it);
                    st[y - 'a'].insert(x - 1);
                    break;
                }
            }
        }
        else
        {
            int cnt = 0;
            int x, y; cin >> x >> y;
            for (int i = 0; i < 26; i++)
            {
                auto it = st[i].lower_bound(x - 1);
                if (it != st[i].end() && *it < y)
                {
                    cnt++;
                }
            }
            cout << cnt << endl;
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