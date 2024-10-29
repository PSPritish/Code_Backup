#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"
namespace Sort
{
    void merge_sort(int l, int r, vector<int> &a);
    void merge(int l, int r, vector<int> &a);
}
void Sort::merge_sort(int l, int r, vector<int> &a)
{
    if(l >= r)
        return;
    int mid = (l + r) / 2;
    merge_sort(l, mid, a);
    merge_sort(mid + 1, r, a);
    merge(l, r, a);
}
void Sort::merge(int l, int r, vector<int> &a)
{
    int i = l;
    vector<int> temp;
    int mid = (l + r) / 2, j = mid + 1;
    while (i <= mid and j <= r)
    {
        if (a[i] > a[j])
            temp.push_back(a[j++]);
        else
            temp.push_back(a[i++]);
    }
    while (i <= mid)
        temp.push_back(a[i++]);
    while (j <= r)
        temp.push_back(a[j++]);
    for (int i{l}; i <= r; i++)
    {
        a[i] = temp[i - l];
    }
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
    Sort::merge_sort(0, n - 1, a);

    for (int i{0}; i < n; i++)
    {
        cout << a[i] << " ";
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