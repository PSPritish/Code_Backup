// You are given an array A of size N.In one operation you can select any non - decreasing subarray and increment all the elements in the subarray by one.Your goal is to make the whole array non - decreasing in minimum operations.
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] > arr[i])
        {
            cnt += arr[i - 1] - arr[i];
        }
    }
    cout << cnt << endl;
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