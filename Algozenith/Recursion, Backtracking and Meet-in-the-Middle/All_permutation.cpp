#include <bits/stdc++.h>
using namespace std;

int n;
map<int, int> mp;
vector<int> cur_per;
void rec(int level)
{
    if (level == n)
    {
        for (auto v : cur_per)
            cout << v << ' ';
        cout << '\n';
        return;
    }

    for (auto &v : mp)
    {
        if (v.second != 0)
        {
            cur_per.push_back(v.first);
            v.second--;
            rec(level + 1);
            v.second++;
            cur_per.pop_back();
        }
    }
    return;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        mp[a]++;
    }

    rec(0);
}