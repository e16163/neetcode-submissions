class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1)
        {
            return false;
        }
        unordered_map<int, vector<int>> adj;
        vector<bool> visited (n, false);
        vector<bool> path (n, false);
        for (auto& e: edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        if (dfs(adj, visited, -1, 0))
        {
            return false;
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) return false;
        }
                
        return true;
    }
        
        
    bool dfs(unordered_map<int, vector<int>>& adj, vector<bool>& visited, int parent, int i)
    {
        if (visited[i])
        {
            return true;
        }
        visited[i] = true;
        for (int n: adj[i])
        {
            if (n == parent)
            {
                continue;
            }
            if (dfs(adj, visited, i, n))
            {
                return true;
            }
        }
        return false;
    }
};
