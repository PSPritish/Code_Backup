
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};
void dfs(Node *root, map<int, vector<int>> &m, int level)
{
    if (root == nullptr)
        return;

    m[level].push_back(root->val);
    dfs(root->left, m, level + 1);
    dfs(root->right, m, level);
}
vector<vector<int>> getDiagonalLevelorderTraversal(Node *root)
{
    vector<vector<int>> v;
    map<int, vector<int>> m;
    dfs(root, m, 0);
    for (auto level : m)
    {
        v.push_back(level.second);
    }

    reverse(v.begin(), v.end());
    return v;
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
        vector<vector<int>> ans = getDiagonalLevelorderTraversal(tree);
        for (auto u : ans)
        {
            for (auto v : u)
            {
                cout << v << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}
