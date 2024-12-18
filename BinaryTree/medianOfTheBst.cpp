
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};
void inOrder(Node *root, vector<int> &res)
{
    if (!root)
        return;
    inOrder(root->left, res);
    res.push_back(root->val);
    inOrder(root->right, res);
}
int getMedian(Node *root)
{
    // Complete the function.
    vector<int> res;
    inOrder(root, res);
    int n = res.size();
    if (n % 2 == 0)
    {
        return (res[n / 2] + res[n / 2 + 1]) / 2;
    }
    return res[n / 2];
}
Node *getBinaryTree(vector<int> &num, int *ind)
{
    if (num[*ind] == -1)
        return NULL;
    Node *node = new Node(num[*ind]);
    (*ind)++;
    node->left = getBinaryTree(num, ind);
    (*ind)++;
    node->right = getBinaryTree(num, ind);
    return node;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        assert(n <= 1000000);
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int ind = 0;
        cout << getMedian(getBinaryTree(arr, &ind)) << "\n";
    }
    return 0;
}
