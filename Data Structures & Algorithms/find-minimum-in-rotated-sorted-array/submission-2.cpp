class Solution {
public:
    int findMin(vector<int> &nums) {
        //target is where n-1>n
        int left = 0; 
        int right = nums.size()-1;
        int mid = nums.size()/2;
        int length = right - left + 1;
        int mini = nums[mid];
        while (length>0)
        {
            
            mid = (right + left + 1)/2;
            if (nums[mid] > nums[right])
            {
                
                left = mid + 1;
                int smaller = min(nums[mid], nums[left]);
                mini = min(mini, smaller);

            }
            else if (nums[mid] < nums[right])
            {
                
                right = mid-1;
                int smaller = min(nums[mid], nums[right]);
                mini = min(mini, smaller);
                
            }
            else if (nums[mid] == nums[right])
            {
                //cout<<"hi";
                int smaller = min(nums[mid], nums[left]);
                mini = min(mini, smaller);
                return mini;
            }
            else if (nums[mid]==nums[left])
            {
                //cout<<"hi";
                int smaller = min(nums[mid], nums[right]);
                mini = min(mini, smaller);
                return mini;
            }
            
            length = right - left + 1;
        }
        return mini;
    }
};
