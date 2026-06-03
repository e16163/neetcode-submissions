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
    int diameterOfBinaryTree(TreeNode* root) {
        if (root==nullptr)
        {
            return 0;
        }
        int currentRootDiameter = maxDepth(root->left) + maxDepth(root->right);

        int leftDiameter = diameterOfBinaryTree(root->left);

        int rightDiameter = diameterOfBinaryTree(root->right);

        return std::max(currentRootDiameter, std::max(leftDiameter, rightDiameter));
        
        
    }
    int maxDepth(TreeNode* root) {
        if (!root)
        {
            return 0;
        }
        return 1 + std::max(maxDepth(root->right), maxDepth(root->left));
        
    }
};
