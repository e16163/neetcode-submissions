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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        s.push(root);
        int seen = 0;
        TreeNode* curr = root;
        
        while (!s.empty() || curr!=nullptr)
        {
            if (curr!=nullptr)
            {
                s.push(curr);
                curr = curr->left;
            }
            else
            {
                TreeNode* node = s.top();
                s.pop();
                seen++;
                if (seen==k)
                {
                    return node->val;
                }
                curr = node->right;
            }

        }
        return -1;
        
    }
};
