class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> indices;
        for (int i = 0; i < nums.size(); i++) {
            if (indices[nums[i]] == 0) {
                indices[nums[i]] = i + 1;
            }
            else {
                if (abs(i + 1 - indices[nums[i]]) <= k) {
                    return true;
                }
                indices[nums[i]] = i + 1;
            }
        }
        return false;
    }
};