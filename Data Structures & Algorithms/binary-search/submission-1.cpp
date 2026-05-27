class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int mid = nums.size()/2;
        int length = nums.size();
        while (length>0)
        {
            mid = (right+left+1)/2;
            if (target>nums[mid])
            {
                cout<<"larger: "<<target<<" "<<nums[mid]<<endl;
                left = mid+1;
            }
            else if (target<nums[mid])
            {
                cout<<"smaller: "<<target<<" "<<nums[mid]<<endl;
                right = mid-1;
            }
            else if (target==nums[mid])
            {
                
                return mid;
            }
            length = right-left+1;
        }
        return -1;

        
    }
};
