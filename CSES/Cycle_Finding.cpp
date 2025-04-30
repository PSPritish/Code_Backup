#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"

// Note: The DFS function is not used and can be removed if not needed.

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> edges;
    vector<int> par(n + 1, -1);

    // Clear the global adj list for each test case if using multiple tests.
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
        adj[a].push_back(b);
    }
    if (n == 1 and m == 1 and get<2>(edges[0]) < 0)
    {
        cout << "YES\n";
        cout << 1 << " " << 1;
        return;
    }

    // Initialize all distances to 0 for negative cycle detection.
    vector<int> dist(n + 1, 0);

    // Relax edges n-1 times.
    for (int i = 1; i < n; i++)
    {
        for (auto e : edges)
        {
            auto [a, b, c] = e;
            if (dist[b] > dist[a] + c)
            {
                dist[b] = dist[a] + c;
                par[b] = a;
            }
        }
    }

    int node = -1;
    // Check for negative cycle.
    for (auto e : edges)
    {
        auto [a, b, c] = e;
        if (dist[b] > dist[a] + c)
        {
            node = b; // it's common to use the updated vertex.
            break;
        }
    }

    if (node != -1)
    {
        cout << "YES\n";
        // Move 'node' back n times to ensure it's on the cycle.
        for (int i = 0; i < n; i++)
        {
            node = par[node];
        }
        int cycle_start = node;
        vector<int> cycle;
        cycle.push_back(node);
        node = par[node];
        while (node != cycle_start)
        {
            cycle.push_back(node);
            node = par[node];
        }
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());
        for (auto v : cycle)
            cout << v << " ";
    }
    else
    {
        cout << "NO";
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t; // Uncomment if multiple test cases are provided.
    while (t--)
        solve();
}
