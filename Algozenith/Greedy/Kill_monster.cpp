// There are N monsters in front of you.To defeat the i - th of them you need an army of Ai soldiers, Bi of which will be killed during the battle.Now you want to know the minimal number of soldiers you need to recruit in order to kill all the monsters.You don't care about the order of battles: the only thing that matters is that none of the monsters will be left alive.
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"

void solve()
{
    int n;
    cin >> n;

    vector<pair<int, int>> v;
    pair<int, int> rem[n];
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
        rem[i] = {a - b, a};
    }

    sort(rem, rem + n);
    reverse(rem, rem + n);

    int ans = rem[0].second;
    int req = 0;
    for (int i = 1; i < n; i++)
    {

        ans += rem[i].second - rem[i - 1].first;
    }
    cout << ans << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int i;
    cin >> i;
    while (i--)
        solve();
}