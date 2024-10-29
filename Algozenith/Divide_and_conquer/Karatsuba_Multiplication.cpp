#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"
using ll = long long;
int n;
void multiply(const ll A[], const ll B[], ll C[], int n)
{
    int p = (n + 1) / 2;

    if (n == 1)
    {
        C[0] = A[0] * B[0];
        C[1] = A[0] * B[1] + A[1] * B[0];
        C[2] = A[1] * B[1];
        return;
    }
    ll A_L[p], A_M[p], A_R[p], B_L[p], B_M[p], B_R[p];
    ll C_L[n], C_M[n], C_R[n];

    for (int i = 0; i < p; i++)
    {
        A_L[i] = A[i];
        B_L[i] = B[i];
        A_R[i] = A[p + i];
        B_R[i] = B[p + i];
        A_M[i] = A[i] + A[p + i];
        B_M[i] = B[i] + B[p + i];
    }

    multiply(A_L, B_L, C_L, p - 1);
    multiply(A_R, B_R, C_R, p - 1);
    multiply(A_M, B_M, C_M, p - 1);

    for (int i = 0; i < n; i++)
    {
        C_M[i] -= C_L[i];
        C_M[i] -= C_R[i];
    }

    for (int i = 0; i < (2 * n) + 1; i++)
    {
        C[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        C[i] += C_L[i];
        C[p + i] += C_M[i];
        C[(2 * p) + i] += C_R[i];
    }

    return;
}
void solve()
{
    cin >> n;
    ll A[n + 1], B[n + 1], C[2 * n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < n + 1; i++)
    {
        cin >> B[i];
    }
    multiply(A, B, C, n);
    for (int i = 0; i < ((2 * n) + 1); i++)
    {
        cout << C[i] << " ";
    }
    cout << '\n';
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
