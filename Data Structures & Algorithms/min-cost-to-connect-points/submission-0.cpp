class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int len = points.size();
        unordered_map<int, vector<pair<int, int>>> adj;
        for (int i = 0; i < len; i++)
        {
            int x = points[i][0];
            int y = points[i][1];
            for (int j = i + 1; j < len; j++)
            {
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dist = abs(x2 - x) + abs(y2 - y);
                adj[i].push_back({dist, j});
                adj[j].push_back({dist, i});
            }
        }
        int cost = 0;
        int count = 0;
        vector<bool> visit(len, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, 0});
        while (count < len)
        {
            pair<int, int> p = minHeap.top();
            minHeap.pop();
            int c = p.first;
            int i = p.second;
            if (visit[i])
            {
                continue;
            }
            cost += c;
            visit[i] = true;
            count++;
            for (auto& v: adj[i])
            {
                int nextCost = v.first;
                int nextInd = v.second;
                if (!visit[nextInd])
                {
                    minHeap.push({nextCost, nextInd});
                }
            }
        }
        return cost;
    }
};
