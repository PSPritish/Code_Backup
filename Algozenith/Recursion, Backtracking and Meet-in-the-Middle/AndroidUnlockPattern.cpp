#include <bits/stdc++.h>
using namespace std;
#define int long long int
int n;
int ans = 0;
int skip[10][10];
bool visited[9];
int rec(int cur, int remlen)
{
    if (!remlen)
        return 1;
    visited[cur] = true;
    int ans = 0;
    for (int i = 1; i < 10; i++)
    {
        if (!visited[i] && (!skip[cur][i] || visited[skip[cur][i]]))
            ans += rec(i, remlen - 1);
    }
    visited[cur] = false;
    return ans;
}
void solve()
{
    memset(skip, 0, sizeof(skip));
    memset(visited, false, sizeof(visited));
    cin >> n;
    skip[1][3] = skip[3][1] = 2;
    skip[1][7] = skip[7][1] = 4;
    skip[3][9] = skip[9][3] = 6;
    skip[7][9] = skip[9][7] = 8;
    skip[1][9] = skip[9][1] = skip[2][8] = skip[8][2] = skip[3][7] = skip[7][3] = skip[4][6] = skip[6][4] = 5;

    ans += rec(1, n - 1) * 4;
    ans += rec(2, n - 1) * 4;
    ans += rec(5, n - 1);
    cout << ans << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}