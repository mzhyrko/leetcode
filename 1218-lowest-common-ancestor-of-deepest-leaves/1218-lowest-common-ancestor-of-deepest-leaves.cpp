/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* getLca(TreeNode* root, vector<TreeNode*> nodes) {
        if (nodes.empty())
            return nullptr;
        if (nodes.size() == 1)
            return nodes[0];

        function<TreeNode*(TreeNode*, TreeNode*, TreeNode*)> dfs =
            [&](TreeNode* node, TreeNode* p, TreeNode* q) -> TreeNode* {
            if (!node || node == p || node == q)
                return node;

            TreeNode* left = dfs(node->left, p, q);
            TreeNode* right = dfs(node->right, p, q);

            if (left && right)
                return node;
            return left ? left : right;
        };

        TreeNode* lca = nodes[0];
        for (int i = 1; i < nodes.size(); ++i) {
            lca = dfs(root, lca, nodes[i]);
        }
        return lca;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        map<int, vector<TreeNode*>> mp;

        int level = 0;
        queue<pair<TreeNode*, int>> q;

        q.push({root, 0});

        while (!q.empty()) {
            int len = q.size();
            level++;
           
            for (int i = 0; i < len; i++) {
                auto cur = q.front();
                int row = cur.second;
                auto node = cur.first;
                
                mp[row].push_back(node);
                level = row;
                q.pop();
                if (node->left != nullptr)
                    q.push({node->left, row + 1});
                if (node->right != nullptr)
                    q.push({node->right, row + 1});
            }
        }

        vector<TreeNode*> nodes = mp[level];
        TreeNode* lca = getLca(root, nodes);
        return lca;
    }
};