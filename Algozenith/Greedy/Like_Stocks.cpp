// You are given an array A of n integers and a value k.You can select zero or more non - empty subarrays A[l..r] such that no two subarrays have any index in common, i.e., no two subarrays should overlap.For each chosen subarray A[l..r] add the value A[r] - A[l] - k to your score which is initially zero.Print the max score possible.
#include <bits/stdc++.h>
using namespace std;

#define ll long long

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }

        vector<ll> done(n), in_progress(n);
        done[0] = 0;
        in_progress[0] = -a[0];

        for (int i = 1; i < n; ++i)
        {
            done[i] = max(done[i - 1], a[i] + in_progress[i - 1] - k);
            in_progress[i] = max(in_progress[i - 1], done[i - 1] - a[i]);
        }

        cout << done[n - 1] << "\n";
    }
    return 0;
}