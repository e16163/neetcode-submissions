class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int start = 0; 
        int length = 0; 
        std::map<pair<int,int>, int> window;
        int index = 0;
        vector<int>ans;
        for (int end = 0; end < nums.size(); end++)
        {
            pair<int,int> add = {nums[end],end};
            window[add]++;
            length++;
            if (length==k)
            {
                auto last = window.rbegin();
                pair<int,int> maxi = last->first;
                ans.push_back(maxi.first);
                pair<int,int> rem = {nums[start],start};
                window.erase(rem);
                cout<<nums[start]<<endl;
                start++;
                length--;
            }
        }
        return ans;
    }
};
