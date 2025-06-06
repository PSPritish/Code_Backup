
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};
pair<int, int> check(Node *root, bool &flag) //{min, max}
{
    if (!root)
        return {INT_MAX, INT_MIN};
    auto left = check(root->left, flag);
    auto right = check(root->right, flag);
    if (root->val < left.second || root->val > right.first)
        flag = false;
    return {min(root->val, left.first), max(root->val, right.second)};
}
bool isBst(Node *root)
{
    bool flag = true;
    auto ans = check(root, flag);
    return flag;
    // Complete the function
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
            cin >> arr[i];
        int ind = 0;
        Node *tree = getBinaryTree(arr, &ind);
        if (isBst(tree))
        {
            cout << "yes\n";
        }
        else
        {
            cout << "no\n";
        }
    }
    return 0;
}
