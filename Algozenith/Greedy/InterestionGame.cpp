// Alice and Bob are playing a new game, which is very interesting and fun.The game is as follows :

//     The game starts with two n - sized integer arrays,
//     A and B, and is played by two players, P1 and P2.The players move in alternating turns, with P1 always moving first.During each move, the current player must choose an integer, i, such that 0 ≤ i ≤ n - 1. If the current player is P1, then P1 receives Ai points;
// if the
//     current player is P2, then P2 receives Bi points.Each value of i can be chosen only once.That is, if a value of i is already chosen by some player, none of the players can re - use it.So, the game always ends after n moves.The player with the maximum number of points wins.The arrays A and B are accessible to both the players P1 and P2.So the players make an optimal move at every turn.Given the values of n, A, and B, can you determine the outcome of the game ? P1 is Alice and P2 is Bob.Print ‘Alice’ if Alice will win, 'Bob' if Bob will win, or 'Tie' if they will tie.Assume both players always move optimally.

#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
bool comp(pair<int, int> &a, pair<int, int> &b)
{
    return (a.first + a.second) > (b.first + b.second);
}
void solve()
{
    int n;
    cin >> n;
    int a[n], b[n];
    pair<int, int> arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
        cin >> b[i];

    for (int i = 0; i < n; i++)
    {
        arr[i] = {a[i], b[i]};
    }
    sort(arr, arr + n, comp);

    int flag = 1;
    int ap = 0, bp = 0;
    for (int i = 0; i < n; i++)
    {
        if (flag--)
            ap += arr[i].first;
        else
        {
            bp += arr[i].second;
            flag = 1;
        }
    }
    if (ap > bp)
        cout << "Alice" << endl;
    else if (bp > ap)
        cout << "Bob" << endl;
    else
        cout << "Tie" << endl;
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