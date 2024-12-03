#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"
int chk(int mid, int pow)
{
    int ans = 1;
    for (int i = 0; i <= pow; i++)
    {
        ans *= mid;
    }
    return ans;
}
int binarySearch(int l, int r, int x, int pow)
{
    int hi = r, lo = l;
    while (hi >= lo)
    {
        int mid = (hi + lo) / 2;
        int c = chk(mid, pow);

        if (c == x)
        {
            return mid;
        }
        else if (c < x)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    return -1;
}
void solve()
{
    int q;
    int n;
    cin >> q >> n;
    int ans = binarySearch(1, 1010, n, q);
    if (ans == -1)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
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