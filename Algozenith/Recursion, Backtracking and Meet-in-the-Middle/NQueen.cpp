#include <bits/stdc++.h>
using namespace std;
int n = 8;
bool col[8], dia1[16], dia2[16];
void place(string board[8], int r, int &count)
{
    if (r == 8)
    {
        count++;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (board[r][i] == '.')
        {
            if (!col[i] && !dia1[i - r + 7] && !dia2[i + r])
            {
                col[i] = dia1[i - r + 7] = dia2[i + r] = true;
                place(board, r + 1, count);
                col[i] = dia1[i - r + 7] = dia2[i + r] = false;
            }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s[n];
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    place(s, 0, count);
    cout << count;
}