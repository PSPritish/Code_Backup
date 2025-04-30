// You have given N segments with endpoints and a value.Li and Ri(Li ≤ Ri) are the endpoints(inclusive)
// of the ith segment, and Xi is its value.

//                         Your task is to answer Q queries.Each query contains two integers Y and Z.In each query,
//     you have to find the largest value X within Z, among all the segments which contain point Y.If there is no such segments which contains point Y, then print - 1.
#include <bits/stdc++.h>
using namespace std;

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using lli = int long long;
using ii = pair<lli, lli>;
// #define ld long double;
#define F first
#define S second

const int tot = 1e5 + 5;
const lli mod = 1e9 + 7;
int a[tot];

int main()
{

#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif

    IOS

        lli n;
    cin >> n;
    vector<pair<int, ii>> event;

    // Firstly insert all events of type 0 and 2.
    for (int i = 0; i < n; i++)
    {
        int l, r, x;
        cin >> l >> r >> x;
        event.push_back({l, {0, x}});
        event.push_back({r, {2, x}});
    }

    lli q;
    cin >> q;
    ii queries[q];

    // Now process all queries with event type as 1 and value as their order of occurance.
    for (int i = 0; i < q; i++)
    {
        cin >> queries[i].F >> queries[i].S;
        event.push_back({queries[i].F, {1, i}});
    }

    // Sort all events in order of segment points they cover.
    sort(event.begin(), event.end());

    int ans[q];
    multiset<int> mt; // Multiset to maintain sorted order of values upto current event.

    for (auto i : event)
    {

        // For event of type 0 , simply insert value to multiset
        if (i.S.F == 0)
        {
            mt.insert(i.S.S);
        }

        // For query event , find largest value <= Z and covering the segment point Y.
        else if (i.S.F == 1)
        {
            int z = queries[i.S.S].S;
            auto it = mt.upper_bound(z);
            if (it != mt.begin())
            {
                it--;
                ans[i.S.S] = *it;
            }
            else
                ans[i.S.S] = -1;
        }

        // For event of type 2 , remove value of that segment which has ended.
        else
            mt.erase(mt.find(i.S.S));
    }

    // Finally print all the query values in order they appear.
    for (auto i : ans)
        cout << i << "\n";

    return 0;
}
