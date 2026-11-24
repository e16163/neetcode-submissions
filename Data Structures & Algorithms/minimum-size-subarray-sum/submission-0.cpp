class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int sum = 0;
        int length = 1000000;
        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];
            while (sum >= target) {
                length = min(length, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        if (length == 1000000) {
            return 0;
        }
        return length;
    }
};