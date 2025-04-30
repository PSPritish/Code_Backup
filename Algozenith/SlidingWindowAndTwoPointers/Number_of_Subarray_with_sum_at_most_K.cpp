#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
void solve()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int head = -1, tail = 0;
    int ans = 0;
    int ss = 0;
    while (tail < n)
    {
        while ((head + 1) < n and (arr[head + 1] + ss) <= k)
        {
            head++;
            ss += arr[head];
        }
        ans += (head - tail + 1);

        if (head < tail)
        {

            tail++;
            head = tail - 1;
        }
        else
        {
            ss -= arr[tail];
            tail++;
        }
    }
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a;
    cin >> a;
    while (a--)
        solve();
}