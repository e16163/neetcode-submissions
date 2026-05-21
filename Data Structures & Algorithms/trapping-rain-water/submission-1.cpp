class Solution {
public:
    int trap(vector<int>& height) {
        int start = 0; 
        int end = height.size()-1;
        int leftWall = height[start];
        int rightWall = height[end];
        int ans = 0;
        while (start<end)
        {
           if (height[start]<height[end])
           {
            if (leftWall<height[start])
            {
                leftWall = height[start];
            }
            else
            {
                ans+=(leftWall-height[start]);
            }
            start++;
           }
           else
           {
            if (rightWall<height[end])
            {
                rightWall = height[end];
            }
            else
            {
                ans+=(rightWall-height[end]);
            }
            end--;
           }
        }
        return ans;

    }
};
