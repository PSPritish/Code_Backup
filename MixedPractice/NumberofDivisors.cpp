#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"

void solve()
{
    int n; cin>>n;
    int cnt{0};
    for(int i{1};i*i <= n;i++){
        if(n % i == 0){
            if(i*i == n){
                cnt ++;
            }
            else{
                cnt += 2;
            }
        }
    }
    cout<<cnt<<endl;
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