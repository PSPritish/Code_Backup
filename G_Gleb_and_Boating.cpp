#include <bits/stdc++.h>
using namespace std;

// Global variables for recursion in the "tight" (s < 2*k) case.
int K, S, R;        // K = current initial power k, S = current distance s, R = chosen number of negative blocks
int dp[1100][5000]; // memo: dp[i][pos] for forward block i (i from 2 to R+1) and current position pos

// Recursive function:
//   i: index (starting from 2) of the current forward block to choose
//   pos: current position (guaranteed to be in [0,S])
// In block i the stroke length is L = K - 2*(i-1).
// In every block (except the last) a negative stroke follows; that negative stroke has length = K - (2*i - 1).
// In the last block (i == R+1) we must choose exactly enough strokes so that pos becomes S.
int rec(int i, int pos)
{
    if (i == R + 1)
    {
        int L = K - 2 * R; // stroke length for the last forward block
        if (pos > S)
            return 0;
        if ((S - pos) % L == 0)
        {
            int F = (S - pos) / L;
            if (F >= 1)
                return 1;
        }
        return 0;
    }
    if (pos > S)
        return 0; // cannot exceed s
    if (dp[i][pos] != -1)
        return dp[i][pos];
    int L = K - 2 * (i - 1); // stroke length for current forward block i
    int res = 0;
    int neg = K - (2 * i - 1); // negative stroke that immediately follows block i
    // In forward block i, choose an integer number F (>=1) such that newPos = pos + F * L <= S.
    int maxF = (S - pos) / L;
    for (int F = 1; F <= maxF; F++)
    {
        int newPos = pos + F * L;
        int pos2 = newPos - neg; // after the forced negative stroke
        if (pos2 < 0)
            continue; // cannot go below 0
        if (rec(i + 1, pos2))
        {
            res = 1;
            break;
        }
    }
    dp[i][pos] = res;
    return res;
}

// For a given r (number of forced negative blocks), try to decide if a valid route exists in the "tight" case (s < 2*k).
// In this branch we are forced to have F1 = 1 (one forward stroke of length k)
// so that the first block does not overshoot s.
bool canAchieveForR(int r, int k, int s)
{
    // Set the global values for the current test case.
    K = k;
    S = s;

    if (k > s)
        return false; // as per constraints, but safe check.

    int pos = k; // after block 1 (F1 = 1)
    if (r >= 1)
    {
        int neg = k - 1; // negative stroke in block 1 (always 1 stroke)
        pos = pos - neg;
        if (pos < 0)
            return false;
    }
    R = r;
    for (int i = 0; i <= R + 1; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            dp[i][j] = -1;
        }
    }
    return rec(2, pos) == 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int s, k;
        cin >> s >> k;
        // (1) If s is exactly a multiple of k then paddle straight and finish with power k.
        if (s % k == 0)
        {
            cout << k << "\n";
            continue;
        }
        // (2) For k == 1, the only possible power is 1.
        if (k == 1)
        {
            cout << 1 << "\n";
            continue;
        }
        // (3) If s is “loose” (s >= 2*k), one may adjust with one pair of turns so that final power = k - 2.
        if (s >= 2LL * k)
        {
            int ans = k - 2;
            if (ans < 1)
                ans = 1;
            cout << ans << "\n";
            continue;
        }
        // (4) Otherwise, we are in the "tight" case: s < 2*k.
        // In that case the first stroke (of length k) is forced (since 2 strokes of length k would overshoot s)
        // and negative strokes must also be taken minimally to avoid dropping below 0.
        // We try every possible number r (of forced negative blocks) that is allowable – note that the final power would be k - 2*r.
        // (We only consider r such that k - 2*r >= 1.)
        int r_max = (k - 1) / 2;
        int bestFinal = 1;
        bool found = false;
        for (int r = 1; r <= r_max; r++)
        {
            if (canAchieveForR(r, k, s))
            {
                int finalP = k - 2 * r;
                if (finalP < 1)
                    finalP = 1;
                bestFinal = finalP;
                found = true;
                break; // choose the smallest r (which gives the maximum final power)
            }
        }
        cout << bestFinal << "\n";
    }
    return 0;
}
