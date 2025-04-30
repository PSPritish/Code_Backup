#include <bits/stdc++.h>
using namespace std;

void solve()
{
    multiset<long long> st, gen;
    long long temp, n;
    cin >> n;
    for (long long i = 0; i < 1 << n; ++i)
    {
        cin >> temp;
        st.insert(temp);
    }
    vector<long long> org;
    gen.insert(*st.find(0));
    st.erase(st.find(0));
    while (!st.empty())
    {
        auto se = st.begin();
        org.push_back(*se);
        vector<long long> newgen;
        for (auto &v : gen)
        {
            newgen.push_back(v + *se);
        }
        for (auto &v : newgen)
        {
            gen.insert(v);
            auto it = st.find(v);
            if (it != st.end())
                st.erase(v);
        }
    }
    for (auto it = org.begin(); it != org.end(); it++)
        cout << *it << ' ';
    cout << '\n';
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long i;
    cin >> i;
    while (i--)
        solve();
}