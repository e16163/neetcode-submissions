class Solution {
public:

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.size() == 0)
        {
            return {nums};
        }
        vector<int> copy = vector<int>(nums.begin() + 1, nums.end());
        vector<vector<int>> perms = permute(copy);
        for (const auto& p : perms)
        {
            for (int i = 0; i<= p.size(); i++)
            {
                vector<int> c = p;
                c.insert(c.begin() + i, nums[0]);
                ans.push_back(c);
            }
        }
        return ans;
    }
    
};
