#include <bits/stdc++.h>
using namespace std;
#define int long long int
int n, k;
string s = "";
void rec(int curlen, int openp, int depth)
{
    if (curlen == n)
    {
        assert(openp == 1);
        s += ")";
        if (depth == k)
            cout << s << "\n";
        s.pop_back();
        return;
    }
    if (!openp)
    {
        s += "(";
        rec(curlen + 1, openp + 1, max(depth, openp + 1));
        s.pop_back();
    }
    else
    {
        int remlen = n - curlen + 1;
        if (remlen > openp && openp < k)
        {
            s += "(";
            rec(curlen + 1, openp + 1, max(depth, openp + 1));
            s.pop_back();
        }
        s += ")";
        rec(curlen + 1, openp - 1, max(depth, openp - 1));
        s.pop_back();
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    rec(1, 0, 0);
}