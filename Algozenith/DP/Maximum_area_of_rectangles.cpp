#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"
int findMax(const vector<int> a){
    stack<int> s;
    int maxi = 0;
    for (int i{0}; i <= a.size(); i++)
    {
        while (!s.empty() and (i == a.size() or a[s.top()] >= a[i]))
        {
            int x = s.top();
            s.pop();
            int width = 0;
            if (s.empty())
                width = i;
            else
                width = i - s.top() - 1;
            maxi = max(maxi, a[x] * width);
        }
        s.push(i);
    }
    return maxi;
}
void solve()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i{0}; i<n; i++){
        for(int j{0}; j<m; j++){
            cin>>a[i][j];
        }
    }
    vector<int> dp(m, 0);
    int maxi = 0;
    for(int i{0}; i<n; i++){
        for(int j{0}; j<m; j++){
            if(a[i][j] == 0){
                dp[j] = 0;
            }else{
                dp[j] += a[i][j];
            }
        }
        maxi = max(maxi, findMax(dp));
    }
    cout<<maxi<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}