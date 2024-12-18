#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"

void solve()
{
    int n, q;
    cin >> n >> q;
    queue<int> app[n + 1];
    queue<int> noti;
    int unread = 0;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        if (x == 1)
        {
            app[y].push(unread);
            unread++;
            noti.push(y);
        }
        else if (x == 2)
        {
            while (!app[y].empty())
            {
                app[y].pop();
                unread--;
            }
        }
        else
        {
            while(y--){
                int x = noti.front();
                noti.pop();
                if(!app[x].empty()){
                    app[x].pop();
                    unread--;
                }
            }

        }
        cout << unread << endl;
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