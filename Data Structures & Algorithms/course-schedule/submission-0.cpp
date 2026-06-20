class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<bool> visited (numCourses, false);
        vector<bool> path (numCourses, false);
        for (int i = 0; i < prerequisites.size(); i++)
        {
            vector<int> p = prerequisites[i];
            adj[p[1]].push_back(p[0]);
        }
        for (int i = 0; i < numCourses; i++)
        {
            if (!visited[i])
            {
                if (dfs(adj, visited, path, i))
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool dfs(unordered_map<int, vector<int>>& adj, vector<bool>& visited, vector<bool>& path, int i)
    {
        if (path[i])
        {
            return true;
        }
        if (visited[i])
        {
            return false;
        }
        visited[i] = true;
        path[i] = true;
        for (int n: adj[i])
        {
            if (dfs(adj, visited, path, n))
            {
                return true;
            }
        }
        path[i] = false;
        return false;
    }
};
