
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};
Node *bt(unordered_map<int, int> &mp, vector<int> &postorder, int postStart, int postEnd, int inStart, int inEnd)
{
    if (inStart > inEnd || postStart > postEnd)
        return NULL;

    int brkpt = mp[postorder[postStart]];
    Node *root = new Node(postorder[postStart]);

    root->left = bt(mp, postorder, postStart + 1, postStart + (brkpt - inStart), inStart, brkpt - 1);
    root->right = bt(mp, postorder, postStart + (brkpt - inStart) + 1, postEnd, brkpt + 1, inEnd);

    return root;
}
Node *getBinaryTree(vector<int> &inorder, vector<int> &postorder)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < inorder.size(); i++)
        mp[inorder[i]] = i;
    return bt(mp, postorder, 0, postorder.size() - 1, 0, inorder.size() - 1);
}

void generateArray(Node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        ans.push_back(-1);
        return;
    }
    ans.push_back(root->val);
    generateArray(root->left, ans);
    generateArray(root->right, ans);
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
        vector<int> arr1(n);
        for (int i = 0; i < n; i++)
            cin >> arr1[i];
        vector<int> arr2(n);
        for (int i = 0; i < n; i++)
            cin >> arr2[i];
        Node *tree = getBinaryTree(arr1, arr2);
        vector<int> ans;
        generateArray(tree, ans);
        for (auto v : ans)
            cout << v << " ";
        cout << "\n";
    }
    return 0;
}
