// You are given a string s and two integers x and y.You can perform two types of operations any number of times.

//     Remove substring "ab" and
//     gain x points.

//     For example,
//     when removing "ab" from "cabxbae" it becomes "cxbae".

//         Remove substring "ba" and
//         gain y points.

//         For example,
//     when removing "ba" from "cabxbae" it becomes "cabxe".

//     Return the maximum points you can gain after applying the above operations on s.
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
void solve()
{
    int x, y; // assume x > y
    string s;
    cin >> s >> x >> y;
    string a = "ab", b = "ba";
    if (x < y)
        swap(x, y), swap(a, b);
    stack<char> st;

    int ans = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (!st.empty() and st.top() == a[0] and s[i] == a[1])
        {
            st.pop();

            ans += x;
        }
        else
            st.push(s[i]);
    }
    string rem;
    while (!st.empty())
    {
        rem += st.top();
        st.pop();
    }
    reverse(rem.begin(), rem.end());
    for (int i = 0; i < rem.length(); i++)
    {
        if (!st.empty() and st.top() == b[0] and rem[i] == b[1])
        {
            st.pop();
            ans += y;
        }
        else
            st.push(rem[i]);
    }
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a;
    cin >> a;
    while (a--)
        solve();
}