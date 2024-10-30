#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
int freq[1000100];

void solve()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        freq[arr[i]] = 0;
    }

    int distinct_element = 0;
    int head = -1, tail = 0;
    int ans = 0;
    while (tail < n)
    {
        while (head + 1 < n and (distinct_element < k or freq[arr[head + 1]] >= 1))
        {
            head++;
            if (freq[arr[head]] == 0)
                distinct_element++;
            freq[arr[head]]++;
        }
        ans += (head - tail + 1);

        if (head < tail)
        {
            tail++;
            head = tail - 1;
        }
        else
        {
            freq[arr[tail]]--;
            if (freq[arr[tail]] == 0)
                distinct_element--;
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