class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        map<int, int> ns;
        for (int i = 0; i<nums.size(); i++)
        {
            ns[nums[i]] = i;
        }
        for (int i = 0; i<nums.size(); i++)
        {
            int difference = target - nums[i];
            if (ns[difference]!=0&&ns[difference]!=i)
            {
                ans.push_back(i);
                ans.push_back(ns[difference]);
                return ans;
            }
        }
        return ans;
    }
};
