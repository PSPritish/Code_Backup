// Given an array of N integers, find the sum of XOR of all pairs of numbers in the array, sum of XOR of all subset of numbers in the array, sum of AND of all pairs of numbers in the array, sum of AND of all subset of numbers in the array. Calculate it %1000000007.For pair you should select two index i, j such that i < j.
#include <bits/stdc++.h>
#define endl '\n'
long long mod = 1000000007;
using namespace std;
long long addMod(long long a, long long b)
{
    a = a + b;
    if (a >= mod)
        a -= mod;
    return a;
}
long long nc2(long long x)
{
    return ((x * (x - 1)) / 2) % mod;
}
void solve()
{
    long long sumPairXor = 0;
    long long sumSubsetXor = 0;
    long long sumPairAnd = 0;
    long long sumSubsetAnd = 0;
    long long powerOfTwo[100001];
    powerOfTwo[0] = 1;
    for (long long i = 1; i < 100001; i++)
    {
        powerOfTwo[i] = addMod(powerOfTwo[i - 1], powerOfTwo[i - 1]);
    }
    long long n;
    cin >> n;
    long long a[n];

    for (long long i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (long long i = 0; i < 31; ++i)
    {
        long long cnt = 0;

        for (long long j = 0; j < n; ++j)
        {
            if (a[j] & (1LL << i))
                cnt++;
        }
        sumPairXor = addMod(sumPairXor, (1LL << i) * cnt % mod * (n - cnt) % mod);
        if (cnt)
            sumSubsetXor = addMod(sumSubsetXor, (1LL << i) * powerOfTwo[n - 1] % mod);

        sumPairAnd = addMod(sumPairAnd, (1LL << i) * nc2(cnt) % mod);
        sumSubsetAnd = addMod(sumSubsetAnd, (1LL << i) * (powerOfTwo[cnt] - 1 + mod) % mod);
    }
    cout << sumPairXor << " " << sumSubsetXor << " " << sumPairAnd << " " << sumSubsetAnd << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long a;
    cin >> a;
    while (a--)
        solve();
}