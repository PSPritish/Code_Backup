#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"
string s; 
int k, n;
int cost[26][26];
int dp[110][110][26];
int done[110][110][26];
int rec(int i, int x, int prev){
    if(x < 0) return -1e18;
    if(i == n) return 0;      

    int &ans = dp[i][x][prev];
    if(done[i][x][prev] != -1) return ans;

    ans = -1e18;
    
    for(int j{0};j < 26;j++){
        if(s[i] - 'a' == j){
            ans = max(ans, rec(i + 1, x, j) + cost[prev][j]);
        }
        else{
            ans = max(ans, rec(i + 1, x - 1, j) + cost[prev][j]);
        }
    }
    done[i][x][prev] = true;
    return ans;
}
void solve()
{
    cin >> s >> k;
    int m; cin>>m;
    memset(cost, 0, sizeof(cost));
    for(int i{0};i < m; i++)
    {
        char a, b; int c;
        cin >> a >> b >> c;
        cost[a - 'a'][b - 'a'] = c;    
    }
    n = s.size();
    memset(done, -1, sizeof(done));
    memset(dp, 0, sizeof(dp));
    
    int Max = INT_MIN;
    int ans = INT_MIN;
    for(int i{0};i < 26;i++){
        if(i == s[0] - 'a'){
            ans = rec(1, k, i);
        }
        else{
            ans = rec(1, k - 1, i);
        }
        if(ans > Max)Max = ans;
        
    }
    cout << Max << endl;
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