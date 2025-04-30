#include <bits/stdc++.h>
using namespace std;
int n, a;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> a;
    vector<int> num(n);
    for (int i = 0; i < n; i++)
    {
        num[i] = i + 1;
    }
    for (int i = 0; i < a - 1; i++)
    {
        next_permutation(num.begin(), num.end());
    }
    for (int v : num)
    {
        cout << v << ' ';
    }
    cout << '\n';
}