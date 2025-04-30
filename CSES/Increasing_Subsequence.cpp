#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &v : arr)
        cin >> v;

    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(temp.begin(), temp.end(), arr[i]);
        if (it == temp.end())
        {
            temp.push_back(arr[i]);
        }
        else
        {
            *it = arr[i];
        }
    }
    cout << temp.size();
}

signed main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    //  cin >> t;

    while (t--)
        solve();
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
}