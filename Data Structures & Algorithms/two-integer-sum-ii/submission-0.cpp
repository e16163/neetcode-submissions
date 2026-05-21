class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0; 
        int end = numbers.size()-1;
        int sum = numbers[start] + numbers[end];

        while (sum!=target)
        {
            if (sum>target)
            {
                end--;
            }
            else if (sum<target)
            {
                start++;
            }
            sum = numbers[start]+numbers[end];
            if (sum==target)
            {
                break;
            }
        }
        vector<int> ans;
        ans.push_back(start+1);
        ans.push_back(end+1);
        return ans;
        
    }
};
