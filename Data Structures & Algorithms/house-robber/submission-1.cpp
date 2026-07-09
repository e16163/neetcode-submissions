class Solution {
public:
    int rob(vector<int>& nums) {
        int N = nums.size();
        if (N == 1)
        {
            return nums[0];
        }
        if (N == 0)
        {
            return 0;
        }
        vector<int> houses(N);
        houses[0] = nums[0];
        houses[1] = max(nums[0], nums[1]);
        for (int i = 2; i < N; i++)
        {
            houses[i] = max(houses[i-1], nums[i] + houses[i - 2]);
        }
        return houses[N-1];
    }
};
