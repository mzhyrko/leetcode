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
    int index = 1;
    void solve(TreeNode* root, vector<int>& ind, vector<int>& preorder) {
        if (index == preorder.size()) {
            return;
        }
        if (ind[root->val] > ind[preorder[index]]) {
            root->left = new TreeNode(preorder[index]);
            index++;
            solve(root->left, ind, preorder);
        }

        if (index == preorder.size()) {
            return;
        }

        if (ind[root->val] > ind[preorder[index]]) {
            root->right = new TreeNode(preorder[index]);
            index++;
            solve(root->right, ind, preorder);
        }
    }
    TreeNode* constructFromPrePost(vector<int>& preorder,
                                   vector<int>& postorder) {
        vector<int> ind(preorder.size() + 1, 0);
        for (int i = 0; i < postorder.size(); i++) {
            ind[postorder[i]] = i;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        solve(root, ind, preorder);
        return root;
    }
};