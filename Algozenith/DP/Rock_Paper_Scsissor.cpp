#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

int n, k;
string s;
char moves[] = {'P', 'R', 'S'};
int dp[1010][1010][3];
int back[1010][1010][3];

int score(int level, int move)
{
    if (moves[move] == 'P' && s[level] == 'R')
        return 1;
    if (moves[move] == 'R' && s[level] == 'S')
        return 1;
    if (moves[move] == 'S' && s[level] == 'P')
        return 1;
    return 0;
}

int rec(int level, int left, int last)
{
    if (left < 0)
        return -1e9;
    if (level == n)
        return 0;
    if (dp[level][left][last] != -1)
        return dp[level][left][last];
    int ans = -1e9, move = last;
    for (int i = 0; i < 3; i++)
    {
        if (i == last && ans < rec(level + 1, left, i) + score(level, i))
        {
            ans = (rec(level + 1, left, i) + score(level, i));
            move = i;
        }
        else if (ans < rec(level + 1, left - 1, i) + score(level, i))
        {
            ans = (rec(level + 1, left - 1, i) + score(level, i));
            move = i;
        }
    }
    back[level][left][last] = move;
    return dp[level][left][last] = ans;
}

void generate(int level, int left, int last)
{
    if (level == n)
    {
        cout << endl;
        return;
    }
    int move = back[level][left][last];
    cout << moves[move];
    if (move != last && level > 0)
        left--;
    generate(level + 1, left, move);
}

void solve()
{
    cin >> n >> k >> s;
    memset(dp, -1, sizeof(dp));
    memset(back, -1, sizeof(back));
    int ans = 0, move = 0;
    for (int i = 0; i < 3; i++)
    {
        if (ans < rec(0, k, i))
        {
            move = i;
            ans = rec(0, k, i);
        }
    }
    cout << ans << endl;
    generate(0, k, move);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    };
    return 0;
}