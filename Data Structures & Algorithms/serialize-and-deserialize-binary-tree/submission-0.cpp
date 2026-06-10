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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty())
        {
            TreeNode* node = s.top();
            if (node)
            {
                
                ans += to_string(node->val) + "#";
                s.pop();
                
                s.push(node->right);
                s.push(node->left);
                
            }
            else
            {
                ans+="null#";
                s.pop();
            }

        }
        return ans;
        

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        stack<pair<TreeNode*, bool>> s;
        TreeNode* root = nullptr;
        TreeNode* curr = root;
        while (i < data.length())
        {
            int j = i;
            while (data[j]!='#')
            {
                j++;
            }

            int length = j - i;
            
            string str = data.substr(i, length);
            i = j + 1;
            int num;
            TreeNode* node;
            if (str=="null")
            {
                node = nullptr;
            }
            else
            {
                num = stoi(str);
                node = new TreeNode(num);
            }

            if (s.empty())
            {
                if (node)
                {
                    s.push({node, false});
                    root = node;
                }

            }
            else
            {
                pair<TreeNode*, bool>& top = s.top();
                if (!top.second)
                {
                    top.first->left = node;
                    top.second = true;
                    if (node)
                    {
                        s.push({node, false});
                    }
                    
                }
                else
                {
                    top.first->right = node;
                    s.pop();
                    if (node)
                    {
                        s.push({node, false});
                    }

                }
            }


        }
        return root;
    }
};
