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
    bool isValidBST(TreeNode* root) {
        int min = -1001;
        int max = 1001;
        if (!root)
        {
            return true;
        }
        return check(root, min, max);
    }
    bool check (TreeNode* root, int min, int max)
    {
        if (!root)
        {
            return true;
        }
        
        if (root->val <= min || root->val >= max)
        {
            return false;
        }
        if (root->left && root->right)
        {
            return check(root->left, min, root->val) && check(root->right, root->val, max);        
        }
        else if (root->left)
        {
            return check(root->left, min, root->val);
        }
        else if (root->right)
        {
            return check(root->right, root->val, max); 
        }
        else
        {
            return true;
        }

        
    }
};
