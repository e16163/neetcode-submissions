class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        queue<int> q;
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != val) {
                q.push(nums[i]);
                k++;
            }
        }
        n = q.size();
        int i = 0;
        while (i < n) {
            nums[i] = q.front();
            q.pop();
            i++;
        }
        for (int i = n; n < nums.size(); n++) {
            nums[n] = 0;
        }
        return k;

    }
};