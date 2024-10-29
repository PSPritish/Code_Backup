#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"

void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int temp{0};
    stack<int> s;
    int maxi = 0;
    for (int i{0}; i <= n; i++)
    {
        while (!s.empty() and (i == n or a[s.top()] >= a[i]))
        {
            int x = s.top();
            s.pop();
            int width = 0;
            if (s.empty())
                width = i;
            else
                width = i - s.top() - 1;
            maxi = max(maxi, a[x] * width);
        }
        s.push(i);
    }
    
    cout << maxi << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}