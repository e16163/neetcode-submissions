class Solution {
public:
    int maxArea(vector<int>& heights) {
        int start = 0; 
        int end = heights.size()-1;
        int shorter = min(heights[start],heights[end]);
        int area = shorter * (end-start);
        int ans = 0;
        while (start<end)
        {
            shorter = min(heights[start],heights[end]);
            area = shorter * (end-start);
            ans = max(ans, area);
            cout<<to_string(ans) + " " + to_string(shorter)<<endl;            

            if (heights[start]<=heights[end])
            {
                start++;
            }    
            else
            {
                end--;
            }
        }
        return ans;
    }
};
