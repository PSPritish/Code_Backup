#include <bits/stdc++.h>
using namespace std;
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

#define ll long long
// #define ld long double

// #define size _size
// #define left _left
// #define right _right

const ll INF = 1e18;
ll n;
ll total;
vector<ll> value;
vector<ll> subtree, indp, outdp;
vector<vector<ll>> a;

void indfs(ll u, ll p)
{
    subtree[u] = value[u];
    indp[u] = 0;
    for (ll v : a[u])
    {
        if (v == p)
            continue;
        indfs(v, u);
        subtree[u] += subtree[v];
        indp[u] += indp[v] + subtree[v];
    }
    return;
}

void outdfs(ll u, ll p)
{
    outdp[u] = 0;
    if (p != -1)
    {
        outdp[u] = outdp[p] + indp[p] - indp[u] - 2 * subtree[u] + total;
    }
    for (ll v : a[u])
    {
        if (v == p)
            continue;
        outdfs(v, u);
    }
    return;
}

int main()
{
    IOS

        ll t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        value.resize(n);
        for (ll i = 0; i < n; i++)
            cin >> value[i];
        a.clear();
        a.resize(n);
        for (ll i = 1; i < n; i++)
        {
            ll x, y;
            cin >> x >> y;
            x--;
            y--;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        subtree.resize(n, 0);
        indp.resize(n, 0);
        outdp.resize(n, 0);
        indfs(0, -1);
        total = subtree[0];
        outdfs(0, -1);
        ll mX = -1;
        ll mN = INF;
        for (ll i = 0; i < n; i++)
        {
            mX = max(mX, indp[i] + outdp[i]);
            mN = min(mN, indp[i] + outdp[i]);
        }
        cout << mX << " " << mN << "\n";
    }

    return 0;
}