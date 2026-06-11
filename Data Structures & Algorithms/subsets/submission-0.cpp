class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        dfs(nums, 0, subset, ans);
        return ans;
    }
    void dfs(const vector<int>& nums, int i, vector<int>& subset, vector<vector<int>>& res)
    {
        if (i >= nums.size())
        {
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        dfs(nums, i+1, subset, res);
        subset.pop_back();
        dfs(nums, i + 1, subset, res);
    }
    
};
