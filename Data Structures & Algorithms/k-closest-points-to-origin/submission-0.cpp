class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> maxHeap;
        vector<vector<int>> ans;
        for (int i = 0; i<points.size(); i++)
        {
            vector<int> coord = points[i];
            int distance = coord[0] * coord[0] + coord[1] * coord[1];
            pair<int, vector<int>> p = {distance, coord};
            maxHeap.push(p);
            if (maxHeap.size() > k)
            {
                cout<<"remove"<<endl;
                maxHeap.pop();
            }

        }
        while (!maxHeap.empty())
        {
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return ans;
    }
};
