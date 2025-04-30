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
    int n;
    cin >> n;
    vector<int> digits(n);
    for (int i = 0; i < n; i++)
    {
        cin >> digits[i];
    }

    vector<int> target = {0, 1, 0, 3, 2, 0, 2, 5};

    vector<int> needed(10, 0);
    for (int digit : target)
    {
        needed[digit]++;
    }

    vector<int> count(10, 0);

    for (int i = 0; i < n; i++)
    {
        count[digits[i]]++;

        bool have_enough = true;
        for (int d = 0; d < 10; d++)
        {
            if (count[d] < needed[d])
            {
                have_enough = false;
                break;
            }
        }

        if (have_enough)
        {
            cout << i + 1 << endl;
            return;
        }
    }
    cout << 0 << endl;
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