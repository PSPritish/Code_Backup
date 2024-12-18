
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

int successor(Node *curr, int k)
{
    if (curr == NULL)
        return INT_MAX;
    if (curr->val <= k)
    {
        return successor(curr->right, k);
    }
    return min(successor(curr->left, k), curr->val);
}

int getInorderSuccessor(Node *node, int k)
{
    int val = successor(node, k);
    if (val == INT_MAX)
        return -1;
    return val;
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
        int n, q;
        cin >> n >> q;
        assert(n <= 1000000);
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int ind = 0;
        Node *tree = getBinaryTree(arr, &ind);
        for (int i = 0; i < q; i++)
        {
            int k;
            cin >> k;
            cout << getInorderSuccessor(tree, k) << " ";
        }
        cout << "\n";
    }
    return 0;
}
