#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"

void solve()
{
    int a, b, num1, num2;
    char ch = '+';
    cin >> a >> b;
    // checking whether the final answer will be -ve or +ve
    if (a * b < 0)
        ch = '-';
    a = abs(a);
    b = abs(b);
    if (a % b == 0) // Case 1 : When the numerator is completely divisible by
                    // denominator
    {
        if (ch == '-')
            cout << ch << a / b << endl;
        else
            cout << a / b << endl;
    }

    else
    {
        // Case 2 and 3 , Terminating and recurring
        // Using a map to store the repetition of remainders and their positions
        map<int, int> m1;
        int i = 0, pos;
        string s = "";
        bool flag = true;
        num1 = a / b;
        a = a % b;
        m1.insert({a, i});
        a = a * 10;
        ++i;
        while (1)
        {
            int x, rem;
            x = a / b;
            rem = a % b;
            if (rem == 0) // If rem is 0 that means terminating decimal
            {
                s += char(x + 48);
                break;
            }
            else if (m1.count(rem)) // Checking if the rem has occured previously
            {
                s += char(x + 48);
                pos = m1[rem]; // position for opening parenthesis
                flag = false;
                break;
            }
            // When rem is neither zero or not repeated just insert rem in map
            else
            {
                m1.insert({rem, i});
                ++i;
                s += char(x + 48);
                a = rem * 10;
            }
        }
        if (flag == false)
        {
            if (ch == '-')
                cout << ch << num1 << '.' << s.substr(0, pos) << '('
                     << s.substr(pos, s.length() - pos) << ')' << endl;
            else
                cout << num1 << '.' << s.substr(0, pos) << '('
                     << s.substr(pos, s.length() - pos) << ')' << endl;
        }

        else
        {
            if (ch == '-')
                cout << ch << num1 << '.' << s << endl;
            else
                cout << num1 << '.' << s << endl;
        }
    }
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