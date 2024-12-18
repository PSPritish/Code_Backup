#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"

void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    stack<pair<string, int>> st;
    for(int i = 0;i < n;i++){
        if(s[i] == '('){
            st.push({"(", -1});
        }
        else if(s[i] == ')'){
            int multiplier = 0;
            while(i + 1 < n and s[i + 1] >= '0' and s[i + 1] <= '9'){
                multiplier *= 10;
                multiplier += s[i + 1] - '0';
                i++;
            }
            if(multiplier == 0) multiplier = 1;
            stack<pair<string, int>> temp;
            while(!st.empty()){
                auto x = st.top();
                st.pop();
                if(x.first == "(")break;
                temp.push({x.first, x.second});
            }
            while(!temp.empty()){
                auto x = temp.top();
                temp.pop();
                st.push({x.first, x.second * multiplier});
            }
        }
        else{
            string element = "";
            element += s[i];
            while(i + 1 < n and s[i + 1] >= 'a' and s[i + 1] <= 'z'){
                element += s[i + 1];
                i++;
            }
            int cnt = 0;
            while(i + 1 < n and s[i + 1] >= '0' and s[i + 1] <= '9'){
                cnt *= 10;
                cnt += s[i + 1] - '0';
                i++;
            }
            if(cnt == 0) cnt = 1;
            st.push({element, cnt});
        }
    }
    map<string, int> mp;
    while(!st.empty()){
        auto x = st.top();
        st.pop();
        mp[x.first] += x.second;
    }
    for(auto &x: mp){
        if(x.second == 1)cout << x.first;
        else cout << x.first << x.second;        
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;

    while (t--)
        solve();
}