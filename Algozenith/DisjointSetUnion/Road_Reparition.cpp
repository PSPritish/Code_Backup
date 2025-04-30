#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
bool c(pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b)
{
    return a.second < b.second;
}
class unionfind
{
public:
    int comp, *root, *rank;
    unionfind(int n)
    {
        comp = n;
        root = new int[n + 1], rank = new int[n + 1];
        for (int i = 0; i <= n; i++)
        {
            rank[i] = 1;
            root[i] = i;
        }
    }
    int find(int x)
    {
        if (root[x] == x)
            return x;
        return root[x] = find(root[x]);
    }
    void merge(int a, int b)
    {
        int x = find(a), y = find(b);
        if (rank[x] < rank[y])
            swap(x, y);
        if (x != y)
        {
            root[y] = x;
            rank[x] += rank[y];
            comp--;
            rank[y] = 0;
        }
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    pair<pair<int, int>, int> adj[m];
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[i] = {{a, b}, c};
    }
    sort(adj, adj + m, c);
    unionfind w(n);
    int cost = 0;
    for (int i = 0; i < m; i++)
    {
        int x = adj[i].first.first, y = adj[i].first.second, c = adj[i].second;
        if (w.find(x) != w.find(y))
        {
            w.merge(x, y);
            cost += c;
        }
    }
    if (w.comp != 1)
        cout << "IMPOSSIBLE" << endl;
    else
        cout << cost << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int a; cin>>a; while(a--)
    solve();
}