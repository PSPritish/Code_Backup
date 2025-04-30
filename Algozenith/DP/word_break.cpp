#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"
int dp[1000];
string s;
unordered_map<string, bool> mp;

int rec(int i)
{
    if (i == s.size())
        return 1;
    int &ans = dp[i];
    if (ans != -1)
        return ans;
    ans = 0;
    int k;
    for (k = i; k < s.size(); k++)
    {
        
        if (mp.find(s.substr(i, k - i + 1)) != mp.end())
        {
            ans = ans or rec(k + 1);
        }        
    }
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    cin >> s;
    for (int i{0}; i < n; i++)
    {
        string temp;
        cin >> temp;
        mp[temp] = 1;
    }
    memset(dp, false, sizeof(dp));
    dp[0] = 1;
    for(int i{1};i <= s.size();i++){
        for(int j{1};j <= 20 and j <= i;j++){
            if(mp.find(s.substr(i - j,j)) != mp.end()){
                dp[i] = (dp[i] or dp[i - j]);
            }
        }
    }
    if (dp[s.size()])
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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;

    while (t--)
        solve();
}