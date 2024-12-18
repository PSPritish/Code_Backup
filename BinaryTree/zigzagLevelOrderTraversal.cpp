#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> getZigzagLevelorderTraversal(Node *root)
{
    // Complete the function.
    vector<vector<int>> ans;
    queue<Node *> q;
    if (root)
        q.push(root);
    int level = 0;
while(!q.empty()){
    int n = q.size();
    vector<int> temp;
    while(n--){
        auto node = q.front();
        q.pop();
        temp.push_back(node->val);
        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);        
    }
    if(level%2) reverse(temp.begin(), temp.end());
    ans.push_back(temp);
    level++;
}
    return ans;
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
        vector<vector<int>> ans = getZigzagLevelorderTraversal(tree);
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
