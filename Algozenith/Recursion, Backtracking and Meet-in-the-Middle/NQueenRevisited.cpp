#include <bits/stdc++.h>
using namespace std;
#define int long long int
int n;
int ans = 0;
vector<int> v;
bool check(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (v[i] == col || (v[i] + i) == row + col || (v[i] - i) == (col - row))
            return false;
    }
    if (row >= 1)
    {
        if (v[row - 1] == col - 2 || v[row - 1] == col + 2)
            return false;
    }
    if (row >= 2)
    {
        if (v[row - 2] == col - 1 || v[row - 2] == col + 1)
            return false;
    }
    return 1;
}

void rec(int level)
{
    if (level == n)
    {
        ans++;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (check(level, i))
        {
            v.push_back(i);
            rec(level + 1);
            v.pop_back();
        }
    }
}
void solve()
{
    cin >> n;
    rec(0);
    cout << ans << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}