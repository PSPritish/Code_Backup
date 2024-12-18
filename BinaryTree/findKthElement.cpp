
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};
vector<int> ans;
int getKthElement(Node *node, int k)
{
    return ans[k - 1];
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
        // morries traversal
        Node *cur = tree;
        while (cur != NULL)
        {
            if (cur->left != NULL)
            {
                Node *temp = cur->left;
                while (temp->right != cur and temp->right != NULL)
                {
                    temp = temp->right;
                }
                if (temp->right == cur)
                {
                    ans.push_back(cur->val);
                    temp->right = NULL;
                    cur = cur->right;
                }
                else
                {
                    temp->right = cur;
                    cur = cur->left;
                }
            }
            else
            {
                ans.push_back(cur->val);
                cur = cur->right;
            }
        }
        for (int i = 0; i < q; i++)
        {
            int k;
            cin >> k;
            cout << getKthElement(tree, k) << " ";
        }
        cout << "\n";
        ans.clear();
    }
    return 0;
}
