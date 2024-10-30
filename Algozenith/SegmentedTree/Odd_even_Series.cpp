#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"
int a[2002000];
pair<int, int> t[8000800];
void build(int index, int l, int r)
{
    if (l == r)
    {
        t[index] = {a[l] % 2 == 0, a[l] % 2 == 1};
        return;
    }
    int mid = (l + r) / 2;
    build(2 * index, l, mid);
    build(2 * index + 1, mid + 1, r);
    t[index].first = t[2 * index].first + t[2 * index + 1].first;
    t[index].second = t[2 * index].second + t[2 * index + 1].second;
}
void update(int index, int l, int r, int pos, int val)
{
    if (pos < l or pos > r){
        return;
    }
    if (l == r)
    {
        t[index] = {val % 2 == 0, val % 2 == 1};
        a[l] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(2 * index, l, mid, pos, val);
    update(2 * index + 1, mid + 1, r, pos, val);
    t[index].first = t[2 * index].first + t[2 * index + 1].first;
    t[index].second = t[2 * index].second + t[2 * index + 1].second;
}
int query(int index, int l, int r, int lq, int rq, int type){
    if(l > rq or r < lq){
        return 0;
    }
    if(lq <= l and r <= rq){
        if(type == 1){
            return t[index].first;
        }
        else{
            return t[index].second;
        }
    }
    int mid = (l + r) / 2;
    return query(2 * index, l, mid, lq, rq, type) + query(2 * index + 1, mid + 1, r, lq, rq, type);
}
void solve()
{
    int n, q;
    cin>>n;
    for(int i{0}; i<n; i++){
        cin>>a[i];
    }
    build(1, 0, n-1);
    cin>>q;
    while(q--){
        int type, l, r;
        cin>>type>>l>>r;
        if(type == 0){
            update(1, 0, n-1, l-1, r);
        }
        else if(type == 1){
            cout<<query(1, 0, n-1, l-1, r-1, 1)<<endl;
        }
        else{
            cout<<query(1, 0, n-1, l-1, r-1, 2)<<endl;
        }
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