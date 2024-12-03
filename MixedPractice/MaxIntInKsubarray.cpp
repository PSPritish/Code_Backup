#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"
class monotone_deque
{
    deque<int> dq;
public:
    void insert(int x){
        while(!dq.empty() and dq.back() < x)dq.pop_back();
        dq.push_back(x);
    }
    void remove(int x){
        if(!dq.empty() and dq.front() == x)dq.pop_front();
    }
    int get_max(){
        return dq.front();
    }
};
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    monotone_deque dq;
    for(int i = 0;i < k;i++){
        dq.insert(a[i]);
    }
    cout<<dq.get_max()<<" ";
    for(int i = k;i < n;i++){
        dq.remove(a[i - k]);
        dq.insert(a[i]);
        cout<<dq.get_max()<<" ";
    }
    cout<<endl;
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