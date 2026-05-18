class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq;
        vector<int> top = {0};
        for (int i = 0; i<nums.size(); i++)
        {
            freq[nums[i]]++;
            
        }
        vector<pair<int, int>> arr;
        for (auto i: freq)
        {
            arr.push_back({i.second, i.first});

        }
        sort(arr.rbegin(), arr.rend());
        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            ans.push_back(arr[i].second);
        }
        

        return ans;
    }
};
