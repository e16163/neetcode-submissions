class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;
        unordered_map<int, vector<int>> adj;
        vector<bool> visited (n, false);
        for (auto& e: edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(adj, visited, i, -1);
                ans++;
            }
        }
        
        return ans;
    }
    void dfs(unordered_map<int, vector<int>>& adj, vector<bool>& visited, int i, int parent)
    {
        cout<<i<<endl;
        visited[i] = true;
        for (int n: adj[i])
        {
            if (!visited[n])
            {
                dfs(adj, visited, n, i);
            }
            
        }
        return;
    }
};
