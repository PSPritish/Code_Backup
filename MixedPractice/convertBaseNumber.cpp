#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"

void solve()
{
    string n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    int dec = 0;
    int pow = 1;
    for (int i = static_cast<int>(n.size()) - 1; i >= 0; i--)
    {
        if (n[i] >= '0' and n[i] <= '9')
        {
            dec += (n[i] - '0') * pow;
        }
        else
        {
            dec += (n[i] - 'A' + 10) * pow;
        }
        pow *= a;
    }
    // cout<<dec<<endl;
    string ans = "";
    while (dec)
    {
        int rem = dec % b;
        if (rem <= 9)
        {
            ans += rem + '0';
        }
        else
        {
            ans += rem - 10 + 'A';
        }
        dec /= b;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
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