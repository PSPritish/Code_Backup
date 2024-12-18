#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
void solve()
{
    int n, x;
    cin >> n >> x;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    map<int, int> pos;
    for (int b = n - 2; b >= 0; b--)
    {
        for (int a = b - 1; a >= 0; a--)
        {
            if (pos[x - arr[a] - arr[b]] == 1)
            {
                cout << "YES";
                return;
            }
        }
        int c = b;
        for (int d = c + 1; d < n; d++)
        {
            pos[arr[c] + arr[d]] = 1;
        }
    }
    cout << "NO";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int a; cin>>a; while(a--)
    solve();
}