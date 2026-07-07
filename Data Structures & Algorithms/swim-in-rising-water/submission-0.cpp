class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        const int R = grid.size();
        const int C = grid[0].size();
        
        set<pair<int, int>> visit;
        priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap;
        vector<vector<int>> directions = 
        {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0}
        };
        minHeap.push({grid[0][0], 0, 0});
        visit.insert({0, 0});
        while (!minHeap.empty())
        {
            auto n = minHeap.top();
            minHeap.pop();
            int t = n[0];
            int r = n[1];
            int c = n[2];
            if (r == R - 1 && c == C - 1)
            {
                return t;
            }
            for (const auto& d: directions)
            {
                int nextR = r + d[0];
                int nextC = c + d[1];
                if (nextR < 0 || nextC < 0 || nextR == R || nextC == C || visit.count({nextR, nextC})) 
                {
                    continue;
                }
                visit.insert({nextR, nextC});
                minHeap.push({max(t, grid[nextR][nextC]), nextR, nextC});
            }
        }
        return R * C;
    }
};
