class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> temp;
        
        vector<int> ans(temperatures.size(), 0);        
        
        for (int i = 0; i<temperatures.size(); i++)
        {
            ans[i] = 0;
            while (!temp.empty() &&  temperatures[i]>temp.top().first)
            {
                pair <int, int> calc = temp.top();
                temp.pop();
                int index = calc.second;
                ans[index] = i-index;

            }
            temp.push({temperatures[i], i});
            
        }
        return ans;
        
    }
};
