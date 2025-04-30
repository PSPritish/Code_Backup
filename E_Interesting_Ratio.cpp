// Author: P S Pritish
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"
constexpr int mod = 1e9 + 7;
constexpr int inf = 1e18 + 1;

void solve()
{
    int t;
    cin >> t;
    vector<int> queries(t);
    int maxN = 0;
    for (int i = 0; i < t; i++)
    {
        cin >> queries[i];
        if (queries[i] > maxN)
            maxN = queries[i];
    }

    // Sieve to generate all primes up to maxN.
    vector<bool> isPrime(maxN + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= maxN; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= maxN; j += i)
                isPrime[j] = false;
        }
    }

    vector<int> primes;
    for (int i = 2; i <= maxN; i++)
    {
        if (isPrime[i])
            primes.push_back(i);
    }

    for (int i = 0; i < t; i++)
    {
        int n = queries[i];
        long long ans = 0;
        for (int p : primes)
        {
            if (p > n)
                break;
            ans += n / p; // for each valid g in [1, floor(n/p)]
        }
        cout << ans << "\n";
    }
}

signed main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    //  cin >> t;

    while (t--)
        solve();
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    ////cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
}