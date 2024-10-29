#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
vector<int> dp((int)2e5 + 10, -1);
int rec(int x)
{
    if (x == 0)
        return 0;

    if (dp[x] != -1)
        return dp[x];

    int ans = 0;
    for (int i = 0; (1 << i) <= x; i++)
    {
        if (rec(x - (1 << i)) == 0)
        {
            ans = 1;
            break;
        }
    }
    return dp[x] = ans;
}
void solve()
{
    int n;
    cin >> n;

    auto ans = rec(n);
    if (ans)
        cout << "Vivek" << endl;
    else
        cout << "Abhishek" << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a;
    cin >> a;
    while (a--)
        solve();
}