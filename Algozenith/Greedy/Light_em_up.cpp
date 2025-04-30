// There are n light bulbs in a row. Each bulb is either on or off given in input as 1 or 0 respectively.

// In one operation you can select any k consecutive bulbs and flip their switches, that is, if a bulb was off it becomes on and vice versa.

//                                                                                           Find minimum number of operations to turn all the bulbs on.If it's impossible to do so print -1.
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"

void solve()
{
    int m, k;
    cin >> m >> k;
    vector<int> ar;
    ar.resize(m);
    int pre[m];
    memset(pre, 0, sizeof(pre));
    bool zero = false;
    for (int i = 0; i < m; i++)
    {
        cin >> ar[i];
        if (ar[i] == 0)
            zero = true;
    }
    if (k == 0)
    {
        if (zero)
            cout << "-1\n";
        else
            cout << "0\n";
        return;
    }
    int cnt = 0;
    int count = 0;
    for (int i = 0; i < m - k + 1; i++)
    {
        if (i > 0)
            pre[i] = pre[i - 1] + pre[i];
        if ((ar[i] == 0 && pre[i] % 2 == 0) or (ar[i] == 1 && pre[i] % 2 != 0))
        {
            pre[i] += 1;
            pre[i + k] -= 1;
            cnt++;
        }
    }

    for (int i = m - k + 1; i < m; i++)
    {
        pre[i] = pre[i - 1] + pre[i];
    }
    int ctrl = 1;
    for (int i = m - k + 1; i < m; i++)
    {
        if ((ar[i] == 0 && pre[i] % 2 == 0) or (ar[i] == 1 && pre[i] % 2 != 0))
        {
            ctrl = -1;
            break;
        }
    }

    if (ctrl == -1)
        cout << -1 << endl;
    else
        cout << cnt << endl;
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