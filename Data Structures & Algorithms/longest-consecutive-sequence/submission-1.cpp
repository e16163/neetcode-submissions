class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 1;
        int curr = 1;
        if (nums.size()==0)
        {
            return 0;
        }
        for (int i = 1; i<nums.size(); i++)
        {
            
            cout<<nums[i-1]<<" "<<nums[i]<<endl;
            if (nums[i-1]+1<nums[i])
            {
                ans = max(ans, curr);
                cout<<"break"<<endl;
                curr = 1;
            }
            else if (nums[i-1]!=nums[i])
            {
                curr++;
                ans = max(ans, curr);
            }
        }
        return ans;
    }
};
