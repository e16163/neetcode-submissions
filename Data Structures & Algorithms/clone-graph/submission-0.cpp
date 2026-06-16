/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        map<int, vector<Node*>> copy;
        map<Node*, int> visited;
        Node* temp = node;
        if (temp)
        {
            dfs(temp, visited, copy);
        }
        else
        {
            return nullptr;
        }
        
        map<Node*, Node*> visits;
        
        Node* curr = new Node(node->val);
        visits[node] = curr;
        Node* ans = curr;
        if (curr)
        {
            adjList(node, curr, visits, copy);
        }
        
        return ans;
    }
    void dfs(Node* node, map<Node*, int>& visited, map<int, vector<Node*>>& copy)
    {
        visited[node] = 1;
        
        if (!node->neighbors.empty())
        {
            for (auto& n: node->neighbors)
            {
                copy[node->val].push_back(n);
                if (visited[n]==0)
                {
                    dfs(n, visited, copy);
                }
            }
        }
        return;
    }
    void adjList(Node* node, Node* clone, map<Node*, Node*>& visits, map<int, vector<Node*>>& copy)
    {
        visits[node] = clone;
        cout<<node->val<<endl;
        if (copy[node->val].size() > 0)
        {
            for (auto& n: copy[node->val])
            {
                if (!visits[n])
                {
                    Node* next = new Node(n->val);
                    visits[n] = next;
                    clone->neighbors.push_back(next);
                    adjList(n, next, visits, copy);
                }
                else
                {
                    clone->neighbors.push_back(visits[n]);
                }
            }
        }
        return;
    }
};
