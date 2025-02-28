
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

Node *getLCANode(Node *root, int n1, int n2)
{
    // Complete the function.
    if (root == NULL)
        return NULL;
    if (n1 < root->val and n2 < root->val)
        return getLCANode(root->left, n1, n2);
    else if (n1 > root->val and n2 > root->val)
        return getLCANode(root->right, n1, n2);
    return root;
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
            int k1, k2;
            cin >> k1 >> k2;
            cout << getLCANode(tree, k1, k2)->val << " ";
        }
        cout << "\n";
    }
    return 0;
}
