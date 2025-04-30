#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"
int merge_sort(int l, int r, vector<int> a){
    if(l >= r)return 0;
    if(r - l == 1){
        if(a[l] > a[r]){
            swap(a[l], a[r]);
            return 1;
        }
        return 0;
    }
    int mid = (l + r) / 2;
    int ans = merge_sort(l, mid, a) + merge_sort(mid + 1, r, a);
    int ptr = mid + 1;
    for(int i{l};i <= mid;i++){
        while(a[ptr] < a[i] and ptr <= r ){
            ptr++;
        }
        ans += static_cast<long long>(ptr - mid - 1);
    }
    vector<int> temp;
    for(int i{l};i <= r;i++){
        temp.push_back(a[i]);
    }
    sort(temp.begin(), temp.end());
    for(int i{l};i <= r;i++){
        a[i] = temp[i - l];
    }
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a;
    for (int i{0}; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }  
    cout << merge_sort(0, n - 1, a) << endl;
    

    // for (int i{0}; i < n; i++)
    // {
    //     cout << a[i] << " ";
    // }
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