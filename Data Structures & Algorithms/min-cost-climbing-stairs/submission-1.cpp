class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int steps = cost.size();
        if (steps <= 2)
        {
            return min(cost[0], cost[1]);
        }
        vector<int> dist(steps + 1, -1);
        dist[0] = 0;
        dist[1] = 0;
        for (int i = 2; i <= steps; i++)
        {
            dist[i] = min(dist[i-1] + cost[i-1], dist[i-2] + cost[i-2]);
        }
        return dist[steps];
    }
};
