// Author: P S Pritish
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"
constexpr int mod = 1e9 + 7;
constexpr int inf = 1e18 + 1;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string news = s;
    reverse(news.begin(), news.end());

    // If both are same (palindrome)
    if (s == news)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] != s[i + 1] && k > 0)
            {
                cout << "YES" << endl;
                return;
            }
            else if (s[i] != s[i + 1] && k == 0)
            {
                cout << "NO" << endl;
                return;
            }
        }
        cout << "NO" << endl;
        return;
    }

    // Need to find the first point where the string is not same
    for (int i = 0; i < n; i++)
    {
        if (s[i] != news[i])
        {
            if (s[i] < news[i])
            {
                cout << "YES" << endl;
                return;
            }
            else
            {
                if (k > 0)
                {
                    cout << "YES" << endl;
                    return;
                }
                else
                {
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }
}

signed main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    cin >> t;

    while (t--)
        solve();
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    ////cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
}