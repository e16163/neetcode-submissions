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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>ans;
        TreeNode* pNode = root;
        TreeNode* qNode = root;
        map<TreeNode*, int> visited;
        while (pNode->val != p->val)
        {
            if (p->val > pNode->val)
            {
                visited[pNode]++;
                cout<<pNode->val<<endl;
                pNode = pNode->right;

            }
            else
            {
                visited[pNode]++;
                cout<<pNode->val<<endl;
                pNode = pNode -> left;
            }
        }
        visited[pNode]++;
        cout<<pNode->val<<endl;
        while (qNode->val != q->val)
        {
            if (q->val > qNode->val)
            {
                visited[qNode]++;
                cout<<qNode->val<<endl;
                qNode = qNode->right;

            }
            else
            {
                visited[qNode]++;
                cout<<qNode->val<<endl;
                qNode = qNode -> left;
            }
        }
        visited[qNode]++;
        cout<<qNode->val<<endl;
    
        for (const auto& pair : visited) {
            if (pair.second==2)
            {
                
                ans.push_back(pair.first);
            }
        }
        return ans[ans.size()-1];
    }
};
