// You have given two vectors in N-dimension space, let it be V and W.
// V = <V1, V2, ..., VN>
// W = <W1, W2, ..., WN>

// The dot product is defined as V.W = V1 * W1 + V2 * W2 + ... + VN * WN.

// Now you are allowed to permute numbers in vectors, in order to minimize the dot product. Find the minimum dot product that you can get.

// See sample test cases for more explanation.
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    int v[n], w[n];
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    sort(v, v + n);
    sort(w, w + n);
    reverse(w, w + n);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += w[i] * v[i];
    }
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a;
    cin >> a;
    while (a--)
        solve();
}