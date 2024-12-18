#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"
char get(char c1, char c2, char e, int val)
{
    if (e == '&')
    {
        return (c1 - '0') & (c2 - '0') + '0';
    }
    if (e == '|')
    {
        return (c1 - '0') | (c2 - '0') + '0';
    }
    return (c1 - '0') ^ (c2 - '0') + '0';
}
int eval(string s, int val)
{
    int n = s.length();
    stack<char> st;
    st.push(0);
    for (int i{0}; i < (int)s.length(); i++)
    {
        if (s[i] == '(')
        {
            continue;
        }
        if (s[i] == ')')
        {
            char c2 = st.top();
            st.pop();
            char e = st.top();
            st.pop();
            char c1 = st.top();
            st.pop();
            st.push(get(c1, c2, e, val));
        }
        else
        {
            if (s[i] == 'x')
                st.push('0' + val);
            else if (s[i] == 'X')
                st.push('0' + 1 - val);
            else
                st.push(s[i]);
        }
    }
    return (st.top() - '0');
}
void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    int x = eval(s, 0);
    int y = eval(s, 1);
    if (x == y)
    {
        cout << "0\n";
        return;
    }
    cout << "1\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;

    while (t--)
        solve();
}