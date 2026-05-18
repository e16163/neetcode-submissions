class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int total  = 1;
        vector<int> ans;
        bool zero = false;
        vector<int>zeroes;
        for (int i = 0; i<nums.size(); i++)
        {
            if (nums[i]!=0)
            {
                total*=nums[i];
            }
            else
            {
                zero = true;
                zeroes.push_back(i);
            }

        }
        for (int i  = 0; i<nums.size(); i++)
        {
            if (zeroes.size()>1)
            {
                ans.push_back(0);
            }
            else if (zeroes.size()==1)
            {
                if (i==zeroes[0])
                {
                    ans.push_back(total);
                }
                else
                {
                    ans.push_back(0);
                }
            }
            else
            {
                ans.push_back(total/nums[i]);
            }
            
        }
        return ans;


    }
};
