#include <bits/stdc++.h>
using namespace std;
#define int long long int
bool check(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int a, b, len = 0, ans = 0;

void rec(int cur, int curlen, int totallen)
{
    if (curlen == (totallen + 1) / 2)
    {
        vector<int> d;
        int temp = cur;
        while (temp)
        {
            d.push_back(temp % 10);
            temp /= 10;
        }
        temp = cur;
        for (int i = (totallen % 2); i < (int)d.size(); i++)
        {
            temp *= 10;
            temp += d[i];
        }
        if (temp <= b && temp >= a && check(temp))
        {
            ans++;
        }
        return;
    }

    for (int i = 0; i < 10; i++)
    {
        cur *= 10;
        cur += i;
        rec(cur, curlen + 1, totallen);
        cur /= 10;
    }
    return;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b;
    int temp = b;
    while (temp)
    {
        len++;
        temp /= 10;
    }

    for (int i = 1; i <= len; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            rec(j, 1LL, i);
        }
    }
    cout << ans << '\n';
}