#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, vector<pair<int, int>>> mpr;
        queue<pair<TreeNode *, pair<int, int>>> q;
        q.push(make_pair(root, make_pair(0, 0)));

        while (!q.empty())
        {
            auto itr = q.front();
            q.pop();

            int hlev = itr.second.first, vlev = itr.second.second;
            if (itr.first != NULL)
            {
                mpr[hlev].push_back(make_pair(vlev, itr.first->data));
                q.push(make_pair(itr.first->left, make_pair(hlev - 1, vlev + 1)));
                q.push(make_pair(itr.first->right, make_pair(hlev + 1, vlev + 1)));
            }
        }

        vector<vector<int>> ans;
        for (auto itr = mpr.begin(); itr != mpr.end(); itr++)
        {
            vector<int> temp;
            sort(itr->second.begin(), itr->second.end());
            for (int i = 0; i < itr->second.size(); i++)
            {
                temp.push_back(itr->second[i].second);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};

TreeNode *deserialize(string data)
{
    if (data.empty())
        return nullptr;
    stringstream ss(data);
    string item;
    vector<string> dat;
    while (getline(ss, item, ','))
    {
        dat.push_back(item);
    }
    int i = 0;
    queue<TreeNode *> q;
    TreeNode *root = new TreeNode(stoi(dat[0]));
    q.push(root);
    i++;
    while (!q.empty())
    {
        auto x = q.front();
        q.pop();
        if (i < dat.size() && dat[i] != "x")
        {
            x->left = new TreeNode(stoi(dat[i]));
            q.push(x->left);
        }
        i++;
        if (i < dat.size() && dat[i] != "x")
        {
            x->right = new TreeNode(stoi(dat[i]));
            q.push(x->right);
        }
        i++;
    }
    return root;
}

void solve()
{
    string tr;
    cin >> tr;
    Solution sol;
    auto root = deserialize(tr);
    auto ans = sol.verticalTraversal(root);
    for (auto &x : ans)
    {
        for (auto &y : x)
            cout << y << " ";
        cout << endl;
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
