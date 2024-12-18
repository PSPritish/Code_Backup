#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"
vector<int> kmparray(string &s)
{
    int n = s.length();
    vector<int> kmp(n + 1);
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
    return kmp;
}
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    auto kmp = kmparray(s);
    for (int i = 1; i < n; ++i)
    {
        if ((i + 1) % (i + 1 - kmp[i+ 1]) == 0 && (i + 1) / (i + 1 - kmp[i + 1]) > 1)
        {
            cout << i + 1 << " " << (i + 1) / (i + 1 - kmp[i + 1]) << "\n";
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
    int cnt = 1;
    while (t--)
    {

        cout << "Test case #" << cnt << endl;
        solve();
        cout << endl<<endl;
        cnt++;
    }
}