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
    {
        cin >> a[i];
    }
    stack<int> st;
    vector<int> next_smaller(n, n);
    vector<int> prev_smaller(n, -1);
    for(int i{0};i < n;i++){
        while(!st.empty() and a[st.top()] >= a[i]){
            st.pop();
        }
        if(!st.empty()){
            prev_smaller[i] = st.top();
        }
        st.push(i);
    }
    while(!st.empty()){
        st.pop();
    }
    for(int i{n - 1};i >= 0;i--){
        while (!st.empty() and a[st.top()] >= a[i])
        {
            st.pop();
        }
        if(!st.empty()){
            next_smaller[i] = st.top();
        }
        st.push(i);
    }
    int ans = 0;
    // for(int i{0};i < n;i++){
    //     cout<<prev_smaller[i]<<" "<<next_smaller[i]<<endl;
    // }
    for(int i{0};i < n;i++){
        ans += a[i] * (i - prev_smaller[i]) * (next_smaller[i] - i);
    }
    cout << ans << endl;
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