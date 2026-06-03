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
    bool isBalanced(TreeNode* root) {
        
        if (!root)
        {
            return true;
        }
        else
        {
            if (abs(maxDepth(root->right) - maxDepth(root->left)) > 1)
            {
                return false;
            }
            else
            {
                
                return true && isBalanced(root->right) && isBalanced(root->left);
            }
        }
        return isBalanced(root->right) && isBalanced(root->left);
    }
    int maxDepth(TreeNode* root) {
        if (!root)
        {
            return 0;
        }
        return 1 + std::max(maxDepth(root->right), maxDepth(root->left));
        
    }
};
