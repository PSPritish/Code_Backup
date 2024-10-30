#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
int freq[100100];
void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        freq[arr[i]] = 0;
    }
    int head = -1, tail = 0, ans = 0, distict = 0;
    while (tail < n)
    {
        while (head + 1 < n and freq[arr[head + 1]] == 0)
        {
            distict++;
            head++;
            freq[arr[head]]++;
        }
        ans = max(ans, distict);
        if (head < tail)
        {
            tail++;
            head = tail - 1;
        }
        else
        {
            freq[arr[tail]]--;
            distict--;
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