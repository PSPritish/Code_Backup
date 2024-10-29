// You are given a string S with length N. Each character is assigned a cost for removing it. Find the minimum cost for removing characters such that it does not contain any subsequence ‘hard’.
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define endl "\n"
string s;
int n;
int cost[100100];
vector<vector<int>> dp;
string m = "hard";
int rec(int level, int match)
{
    if (match == 4)
    {
        return 1e18;
    }
    if (level == n)
    {
        return 0;
    }

    if (dp[level][match] != -1)
        return dp[level][match];

    int ans = 1e18;
    if (s[level] == m[match])
    {
        ans = min({ans, rec(level + 1, match) + cost[level], rec(level + 1, match + 1)});
    }
    else
        ans = min({ans, rec(level + 1, match)});

    return dp[level][match] = ans;
}

void solve()
{
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> cost[i];
    }
    dp.assign(n + 1, vector<int>(4, -1));
    cout << rec(0, 0) << endl;
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