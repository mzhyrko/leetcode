/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution
{
public:
    TreeNode* recoverFromPreorder(string S)
    {
        vector<pair<int, int>> nodeList;
        
        // Step 1: Parse the input string to extract depth and value pairs
        parseInput(S, nodeList);
        
        if (nodeList.empty())
        {
            return nullptr;
        } 
        
        // Step 2: Construct the binary tree using DFS
        TreeNode* root = new TreeNode(nodeList[0].second);
        stack<pair<TreeNode*, int>> st;
        st.push({root, 0});

        for (int i = 1; i < nodeList.size(); i++)
        {
            int depth = nodeList[i].first;
            int value = nodeList[i].second;
            TreeNode* node = new TreeNode(value);
            
            // Step 3: Pop stack until we find the correct parent
            while (!st.empty() && st.top().second >= depth)
            {
                st.pop();
            }
            
            // Step 4: Assign left or right child
            if (st.top().first->left == NULL)
            {
                st.top().first->left = node;
            }
            else
            {
                st.top().first->right = node;
            }
            
            // Step 5: Push current node onto the stack
            st.push({node, depth});
        }
        
        return root;
    }
    
    void parseInput(string& S, vector<pair<int, int>>& nodeList)
    {
        int i = 0;
        while (i < S.length())
        {
            int depth = 0;
        
            // Step 6: Count the number of dashes to determine depth
            while (i < S.length() && S[i] == '-')
            {
                depth++;
                i++;
            }
            int value = 0;
            
            // Step 7: Extract the node's value
            while (i < S.length() && isdigit(S[i]))
            {
                value = value * 10 + (S[i] - '0');
                i++;
            }
            
            // Step 8: Add (depth, value) to the list
            nodeList.push_back({depth, value});
        }
    }
};