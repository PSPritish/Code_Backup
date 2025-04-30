#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"

void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    int kmp[n + 1];
    int i = 0, j = -1;
    kmp[0] = -1;
    while (i < n)
    {
        while (j != -1 and s[i] != s[j])
        {
            j = kmp[j];
        }
        j++;
        i++;
        kmp[i] = j;
    }
    for (int i{0}; i <= n; i++)
    {
        cout << kmp[i] << " ";
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;

    while (t--)
        solve();
}