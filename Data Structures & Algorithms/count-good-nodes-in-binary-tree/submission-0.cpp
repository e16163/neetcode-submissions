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

class Solution {
public:
    int goodNodes(TreeNode* root) {
        int ans = 0;
        stack<pair<TreeNode*, int>> s;
        s.push({root, root->val});
        while (!s.empty())
        { 
            pair<TreeNode*, int> p = s.top();
            TreeNode* node = p.first;
            int maxPath = p.second; 
            
            if (node)
            {
                if (node->val >= maxPath)
                {
                    ans++;
                }
                s.pop();
                if (node->right)
                {
                    s.push({node->right, max(node->right->val, maxPath)});
                }
                if (node->left)
                {
                    s.push({node->left, max(node->left->val, maxPath)});
                }
                
            }
           
            
        }
        return ans;

    }
};
