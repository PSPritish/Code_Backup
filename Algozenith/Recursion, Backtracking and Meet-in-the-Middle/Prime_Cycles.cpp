#include <bits/stdc++.h>
using namespace std;
#define int long long int
int ans = 0;
bool isPrime[100];
bool marked[100];
vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
void rec(int m, int n, int prev, int par)
{
    if (!m)
    {
        if (isPrime[prev + 1])
            ans++;
        return;
    }
    for (int i = par + 1; i <= n; i += 2)
    {
        if (!marked[i] && isPrime[i + prev])
        {
            marked[i] = true;
            rec(m - 1, n, i, 1 - par);
            marked[i] = false;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    memset(marked, false, sizeof(marked));
    memset(isPrime, false, sizeof(isPrime));

    for (auto i : prime)
    {
        isPrime[i] = true;
    }

    if (n % 2 != 0)
    {
        cout << 0 << '\n';
        return 0;
    }
    marked[1] = true;

    rec(n - 1, n, 1, 1);
    cout << ans << '\n';
}