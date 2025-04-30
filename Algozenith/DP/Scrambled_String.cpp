
#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

int dp[41][41][41];
string s1, s2;
bool rec(int l, int r, int i)
{
    int j = i + r - l; // relationship... to reduce DP state.

    // we are trying to match if s1[l...r] is scrable of s2[i...j].
    // pruning
    if (l > r || i > j)
        return false;
    // basecase .. if single element, check if same.
    if (l == r)
    {
        if (s1[l] == s2[i])
            return true;
        return false;
    }
    auto &ans = dp[l][r][i];
    if (ans != -1)
        return ans;

    ans = 0; // by default we asume false.

    // if the two strings are same, trivially true.
    if (s1.substr(l, r - l + 1) == s2.substr(i, j - i + 1))
        return ans = 1;

    for (int k = l; k < r; k++)
    {
        // try to take first [l.. k] and [i...k] and rest part.
        ans |= (rec(l, k, i) & rec(k + 1, r, i + k - l + 1));
        // try to take first [l.. k] and [same length of s1] and rest part.
        ans |= (rec(l, k, j - (k - l + 1) + 1) & rec(k + 1, r, i));
    }
    return ans;
}
void solve()
{
    cin >> s1 >> s2;
    memset(dp, -1, sizeof(dp));
    if (rec(0, s1.size() - 1, 0))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}
signed main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);


    int t = 1;
    // int i = 1;
    cin >> t;
    while (t--)
    {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }    
}
