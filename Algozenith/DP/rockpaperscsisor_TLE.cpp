#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"
string s;
map<char,int> mp;

int dp[1010][1010][3];
vector<int> back[1010][1010][3];
int result(int i,int level){//0 = S, 1 = R, 2 = P
    int ch = mp[s[level]];
    if(i == ch) return 0;
    else if(i == 2 && ch == 1) return 1;
    else if(i == 0 && ch == 2) return 1;
    else if(i == 1 && ch == 0) return 1;
    return 0;
}
int rec(int level, int cnt, int prev){
    if(cnt < 0) return -1e18;
    if(level == s.size()) return 0;

    int &ans = dp[level][cnt][prev];
    if(ans != -1) return ans;
    ans = -1e18;
    back[level][cnt][prev] = {};
    for(int i{0};i < 3;i++){
        int temp = rec(level + 1, cnt - ((i != prev)?1:0), i) + result(i, level);
        
        if(ans < temp){
            back[level][cnt][prev] = {i};
            ans = temp;
        }
        else if(ans == temp){
            back[level][cnt][prev].push_back(i);
        }
    }
    return ans;
}
vector<string> all_solution;
string finalans;
map<int, char> rmap;
/*generating all possible solution*/
void generate(int level, int cnt, int prev){
    if(level == s.size()){
        all_solution.push_back(finalans);
        return;
    }
    for(auto &optimal: back[level][cnt][prev]){
        finalans += rmap[optimal];
        generate(level + 1, cnt - ((optimal != prev)?1:0), optimal);
        finalans.pop_back();
    }    
}
void solve()
{
    mp['R'] = 1;
    mp['P'] = 2;
    mp['S'] = 0;
    rmap[1] = 'R';
    rmap[2] = 'P';
    rmap[0] = 'S';
    int n; cin>>n;
    int k;
    cin>>k;
    cin>>s;
    memset(dp, -1, sizeof(dp));
    memset(back, {}, sizeof(back));
    int a = 0;
    int ans = -1e18;
    for(int i{0};i < 3;i++){
        int temp = rec(0, k, i);
        if(ans <= temp){
            a = i;
            ans = temp;
        }
    }

    generate(0, k, a);
    sort(all_solution.begin(), all_solution.end());
    cout << ans << endl;
    cout<<all_solution[0]<<endl;

    all_solution.clear();    
    finalans = "";
    
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