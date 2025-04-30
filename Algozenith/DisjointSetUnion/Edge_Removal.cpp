#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
class setunion
{
public:
    int *rank, *root, comp = 0;
    setunion(int n)
    {
        rank = new int[n + 1];
        root = new int[n + 1];
        comp = n;
        for (int i = 0; i <= n; i++)
        {
            rank[i] = 1;
            root[i] = i;
        }
    }

    int find(int x)
    {
        if (x == root[x])
            return x;
        return root[x] = find(root[x]);
    }
    void merge(int a, int b)
    {
        int x = find(a), y = find(b);
        // x > y
        if (rank[x] < rank[y])
        {
            swap(x, y);
        }
        if (x != y)
        {
            root[y] = x;
            rank[x] += rank[y];
            rank[y] = 0;
            comp--;
        }
    }
};

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;

    pair<int, int> edge[m + 1], querry[q];
    bool marked[m + 1];
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        edge[i] = {x, y};
    }

    memset(marked, false, sizeof(marked));

    for (int i = 0; i < q; i++)
    {
        int t;
        cin >> t;
        if (t == 2)
            querry[i] = {2, -1};
        else
        {
            int x;
            cin >> x;
            querry[i] = {1, x};
            marked[x] = true;
        }
    }
    setunion w(n);
    for (int i = 1; i <= m; i++)
    {
        if (!marked[i])
        {
            int u = edge[i].first;
            int v = edge[i].second;
            w.merge(u, v);
        }
    }
    vector<int> ans;
    for (int i = q - 1; i >= 0; i--)
    {
        if (querry[i].first == 2)
            ans.push_back(w.comp);
        else
        {
            int x = querry[i].second;
            w.merge(edge[x].first, edge[x].second);
        }
    }
    reverse(ans.begin(), ans.end());

    for (auto v : ans)
        cout << v << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int a; cin>>a; while(a--)
    solve();
}