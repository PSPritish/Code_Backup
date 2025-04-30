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
    int freq[100100];
    memset(freq, 0, sizeof(freq));
    int b = 0, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        freq[a[i]]++;
        if (a[i] > b)
        {
            cnt++;
        }
        if(cnt > b){
            b++;
            cnt -= freq[b];
        }
        cout<<b<<" ";
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