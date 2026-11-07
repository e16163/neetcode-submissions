class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int ans = 0;
        int length = 0;
        queue<int> index;
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 1) {
                length++;
            } else if (nums[right] == 0) {
                if (k > 0) {
                    index.push(right);
                    length++;
                    k--;
                } else {
                    if (!index.empty()) {
                        left = index.front() + 1;
                        index.pop(); 
                    } else {
                        left = right + 1;
                    }

                    length = right - left + 1;
                }
            }
            ans = max(ans, length);
        }
        return ans;
    }
};