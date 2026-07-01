class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto& v: times)
        {
            adj[v[0]].push_back({v[1], v[2]});
        }
        vector<int> distance(n + 1, INT_MAX);
        distance[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, k});
        while (!q.empty())
        {
            int dist = q.top().first;
            int node = q.top().second;
            q.pop();
            if (dist > distance[node])
            {
                continue;
            }
            for (auto& v: adj[node])
            {
               if (distance[node] + v.second < distance[v.first])
                {
                  distance[v.first] = distance[node] + v.second;
                    q.push({distance[v.first], v.first});
                }
            }
        }
        int time = 0;
        for (int i = 1; i <= n; i++)
        {
            if (distance[i] == INT_MAX)
            {
                return -1;
            }
           time = max(time, distance[i]);
        }
        return time;

    }
};
