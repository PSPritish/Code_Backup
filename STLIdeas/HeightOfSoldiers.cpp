#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> nextSmaller(n, n);
    stack<int> st;
    vector<int> prevSmaller(n, -1);
    for (int i{0}; i < n; i++)
    {
        while (!st.empty() and a[st.top()] >= a[i])
            st.pop();
        if (!st.empty())
            prevSmaller[i] = st.top();
        st.push(i);
    }
    while (!st.empty())
        st.pop();
    for (int i{n - 1}; i >= 0; i--)
    {
        while (!st.empty() and a[st.top()] >= a[i])
            st.pop();
        if (!st.empty())
            nextSmaller[i] = st.top();
        st.push(i);
    }

    vector<int> ans(n, -1e9);
    for (int i = 0; i < n; i++)
    {
        int x = nextSmaller[i] - prevSmaller[i] - 2; // because it is zero indexed
        // cout<<x<<" ";
        ans[x] = max(ans[x], a[i]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        ans[i] = max(ans[i], ans[i + 1]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;

    while (t--)
        solve();
}