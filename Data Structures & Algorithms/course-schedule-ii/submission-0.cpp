class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //vector<int> path (numCourses, 0);
        unordered_map<int, vector<int>> adj;
        unordered_set<int> visited;
        unordered_set<int> path;
        
        for (int i = 0; i < prerequisites.size(); i++)
        {
            vector<int> p = prerequisites[i];
            adj[p[0]].push_back(p[1]);
        }
        vector<int> ans;
        for (int i = 0; i < numCourses; i++)
        {
            if (!dfs(adj, visited, path, ans, i))
            {
                return {};
            }
        }
        
        return ans;
    }
    bool dfs(unordered_map<int, vector<int>>& adj, unordered_set<int>& visited, unordered_set<int>& path, vector<int>& ans, int i)
    {
        cout<<i<<endl;
        if (path.count(i))
        {
            return false;
        }
        if (visited.count(i))
        {
            return true;
        }
        path.insert(i);
        if (adj.count(i))
        {
            for (int p: adj[i])
            {
                if (!dfs(adj, visited, path, ans, p))
                {
                    return false;
                }
            }
        }
        path.erase(i);
        visited.insert(i);
        ans.push_back(i);
        return true;
    }
};
