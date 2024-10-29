#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define int int64_t
int dp[105][100100];

int rec(int level, int rem_sum, vector<int> &arr)
{
    // prune statement
    if (rem_sum < 0)
        return 0;
    // base case
    if (level == (int)arr.size())
    {
        if (rem_sum == 0)
        {
            return 1;
        }
        else
            return 0;
    }
    // cache
    if (dp[level][rem_sum] != -1)
    {
        return dp[level][rem_sum];
    }
    // transition
    int ans = 0;
    if (rec(level + 1, rem_sum - arr[level], arr))
    {
        ans = 1;
    }
    else if (rec(level + 1, rem_sum, arr))
    {
        ans = 1;
    }
    // save and return
    return dp[level][rem_sum] = ans;
}
vector<int> sol;
bool solution(int level, int left, vector<int> &arr)
{
    // base case
    if (level == (int)arr.size() && left == 0)
    {
        return 1;
    }
    bool ans = 0;
    // transition check
    if (rec(level + 1, left - arr[level], arr))
    {
        sol.push_back(level);
        solution(level + 1, left - arr[level], arr);
        ans = 1;
    }

    else if (rec(level + 1, left, arr))
    {
        solution(level + 1, left, arr);
        ans = 1;
    }

    return ans;
}
vector<vector<int>> subset_queries(vector<int> &arr, vector<int> &queries)
{
    memset(dp, -1, sizeof(dp));
    vector<vector<int>> ans;
    for (auto q : queries)
    {
        sol.clear();
        if (solution(0, q, arr))
        {

            ans.push_back(sol);
        }
        else
            ans.push_back(vector<int>(1, -1));
    }

    return ans;
}

void solve()
{
    int N, Q;
    cin >> N >> Q;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    vector<int> queries(Q);
    for (int i = 0; i < Q; i++)
        cin >> queries[i];
    auto ans = subset_queries(arr, queries);

    // checker.
    if (ans.size() != Q)
    {
        cout << 101 << endl;
        return;
    }
    for (int i = 0; i < Q; i++)
    {
        auto x = ans[i];
        if (x.size() == 0)
        {
            cout << 101 << endl;
            continue;
        }
        if (x.size() == 1 && x[0] == -1)
        {
            cout << -1 << endl;
            continue;
        }
        ll sum = 0, p = -10;
        for (auto y : x)
        {
            if (y < 0 || y >= N || p >= y)
            { // valid 0-indexed.
                sum = -1111;
                break;
            }
            p = y;
            sum += arr[y];
        }
        if (sum == queries[i])
        {
            cout << 1 << endl;
        }
        else
            cout << 101 << endl;
    }
    // for(int i = 0; i < N;i ++){
    //     for(int j = 0;j < Q;j++)
    //         cout<<dp[i][j];
    //     cout<<endl;
    // }
}
signed main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    // int i = 1;
    // cin >> t;
    while (t--)
    {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
}