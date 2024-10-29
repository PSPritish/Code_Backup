// You are given a list of N intervals. The i-th interval is [li, ri), which denotes a range of numbers greater than or equal to li and strictly less than ri.
// Find The minimum integer y such that for all possible combinations of y intervals from the given N interval, it does cover [0, L).
#include <bits/stdc++.h>

using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using lli = int long long;
lli n, n2;
lli tot = 1e9 + 10;

int main()
{
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif

    IOS
        lli t;

    // cin>>t;
    // while(t--){
    int n;
    lli l;
    cin >> n >> l;
    lli x, y;
    vector<pair<lli, int>> event;

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        event.push_back({x, +1});
        event.push_back({y, -1});
    }
    sort(event.begin(), event.end()); // sort all the events

    int cnt = 0; // keeps count of number of intervals covering that point.
    int ans = n + 1;

    for (int i = 0; i + 1 < (int)event.size(); i++)
    {

        cnt += event[i].second;
        if (event[i].first != event[i + 1].first)
        {
            ans = min(ans, cnt);
        }
    }
    // all points are covered by atleast "ans" no. of intervals
    cout << n - ans + 1 << "\n";

    //}
    return 0;
}
