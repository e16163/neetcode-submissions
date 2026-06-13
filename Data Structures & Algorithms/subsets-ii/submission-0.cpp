class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> subset;
        genSubsets(nums, subset, 0, ans);
        return ans;
    }
    void genSubsets(vector<int>& nums, vector<int>& subset, int i, vector<vector<int>>& ans)
    {
        if (i >= nums.size())
        {
            ans.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        genSubsets(nums, subset, i+1, ans);
        subset.pop_back();
        int j = i;
        while (j + 1 < nums.size() && nums[j]==nums[j+1])
        {
            j++;
        }
        i = j;
        genSubsets(nums, subset, i+1, ans);

        
    }

};
