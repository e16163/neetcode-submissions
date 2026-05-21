class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> triplets;
        map<vector<int>, int> combos;
        //selecting mid
        for (int i = 0; i<nums.size()-2; i++)
        {
            int mid = nums[i];
            int start = i+1;
            int end = nums.size()-1;
            int sum = mid + nums[start] + nums[end];
            if (sum==0)
            {
                //cout<<to_string(mid)+" "+to_string(nums[start])+" "+to_string(nums[end])<<endl;
                vector<int> ans = {mid, nums[start],nums[end]};
                sort(ans.begin(), ans.end());
                if (combos[ans]<1)
                {
                    combos[ans]++;
                    triplets.push_back(ans);
                }
                else
                {
                    combos[ans]++;
                }
                /*while (sum==0)
                {
                    start++;
                    sum = mid + nums[start] + nums[end];
                    if (start>=end)
                    {
                        break;
                    }
                }*/
               
            }
            while (start<end)
            {
                //cout<<to_string(mid)+" "+to_string(nums[start])+" "+to_string(nums[end])<<endl;
                sum = mid + nums[start] + nums[end];
               if (sum>0)
               {
                    end--;
                    if (start==end)
                    {
                        break;
                    }
                                   
               }
               if (sum<0)
               {
                    start++;
                    if (start==end)
                    {
                        break;
                    }
               }
               sum = mid + nums[start] + nums[end];
               if (sum==0)
               {
                    
                    vector<int> ans = {mid, nums[start],nums[end]};
                    
                    //cout<<"combo: " + to_string(mid)+" "+to_string(nums[start])+" "+to_string(nums[end])<<endl;
                    sort(ans.begin(), ans.end());
                    if (combos[ans]<1)
                    {
                        combos[ans]++;
                        triplets.push_back(ans);
                    }
                    else
                    {
                        combos[ans]++;
                    }
                    start++;
               }
               if (start>=end)
               {
                break;
               }
            }
        }
        return triplets;
    }
};
