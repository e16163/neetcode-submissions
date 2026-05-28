class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int mid = (right + left + 1)/2;
        int length = nums.size();
        if (nums[left]<nums[right])
        {
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
        }

        else
        {
            while (length > 0)
            {
                if (length==1)
                {
                    if (target==nums[mid])
                    {
                        return 0;
                    }
                    else
                    {
                        return -1;
                    }
                }
                if (length==2)
                {
                    if (nums[left]==target)
                    {
                        return left;
                    }
                    else if (nums[right]==target)
                    {
                        return right;
                    }
                    else
                    {
                        return -1;
                    }
                }
                mid = (right + left + 1)/2;
                if (target > nums[mid])
                {
                    if (target < nums[right])
                    {
                        left = mid + 1;
                        if (target==nums[left])
                        {
                            return left;
                        }
                    }
                    else if (target > nums[right])
                    {
                        right = mid - 1;
                        if (target==nums[left])
                        {
                            return left;
                        }
                    }
                    else if (target==nums[right])
                    {
                        return right;
                    }
                }
                else if (target < nums[mid])
                {
                    if (target < nums[right])
                    {
                        if (nums[mid]>nums[right])
                        {
                            left = mid + 1;
                            if (target==nums[left])
                            {
                                return left;
                            }
                        }
                        else
                        {
                            right = mid - 1;
                            if (target==nums[left])
                            {
                                return left;
                            }
                        }
                        
                    }
                    else if (target > nums[right])
                    {
                        right = mid - 1;
                        if (target==nums[left])
                        {
                            return left;
                        }
                    }
                    else if (target==nums[left])
                    {
                        return left;
                    }
                }
                else if (target==nums[mid])
                {
                    return mid;
                }
                /*else if (mid==right)
                {
                    return -1;
                }
                else if (mid==left)
                {
                    return -1;
                }*/
                length = (right - left + 1);
            }
        }
        
        return -1;
        
    }
};
