#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"
int bubble_sort(vector<int> &a, int l,int  r)
{
    if(l >= r) return 0;
    if(l == r - 1){
        if(a[l] > a[r]){
            swap(a[l], a[r]);
            return 1;
        }
        return 0;
    }
    int m = (l + r) / 2;
    int ans = bubble_sort(a, l, m) + bubble_sort(a, m + 1, r);
    int ptr = m + 1;

    for(int i{l};i <= m;i++){
        while (ptr <= r and a[i] > a[ptr] )
        {
            ptr++;
        }
        ans += ptr - (m + 1);
    }
    vector<int> b;
    for(int i{l};i <= r;i++){
        b.push_back(a[i]);
    }

    sort(b.begin(), b.end());
    for(int i{l};i <= r;i++){
        a[i] = b[i - l];
    }
    return ans;
}
void solve()
{
    int n; cin>>n;
    vector<int> a;
    for(int i{0};i < n;i++){
        int x; cin>>x;
        a.push_back(x);
    }
    
    
    cout<<bubble_sort(a,0, n -1)%2<<endl;
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