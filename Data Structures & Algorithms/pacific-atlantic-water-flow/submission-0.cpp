class Solution {
public:
//dfs
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        const int rows = heights.size();
        const int cols = heights[0].size();
        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                if (r == 0 || c == 0)
                {
                    dfsP(heights, pacific, r, c);
                }
                if (r == rows - 1 || c == cols - 1)
                {
                    dfsA(heights, atlantic, r, c);
                }
            }
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (pacific[i][j])
                {
                    if (atlantic[i][j])
                    {
                        ans.push_back({i, j});
                    }
                }
            }
        }
        return ans;
    }
    void dfsA(vector<vector<int>>& heights, vector<vector<bool>>& atlantic, int r, int c)
    {
        cout<<r+1<<" "<<c+1<<endl;
        atlantic[r][c] = true;
        
        if (r - 1 >= 0 && heights[r][c] <= heights[r-1][c] && !atlantic[r-1][c])
        {
            dfsA(heights, atlantic, r-1, c);
        }
        if (r + 1 < heights.size() && heights[r][c] <= heights[r+1][c] && !atlantic[r+1][c])
        {
            dfsA(heights, atlantic, r+1, c);
        }
        if (c - 1 >= 0 && heights[r][c] <= heights[r][c-1] && !atlantic[r][c-1])
        {
            dfsA(heights, atlantic, r, c-1);
        }
        if (c + 1 < heights[0].size() && heights[r][c] <= heights[r][c+1] && !atlantic[r][c+1])
        {
            dfsA(heights, atlantic, r, c+1);
        }
        return;
    }
    void dfsP(vector<vector<int>>& heights, vector<vector<bool>>& pacific, int r, int c)
    {
        cout<<r+1<<" "<<c+1<<endl;
        pacific[r][c] = true;
        
        if (r - 1 >= 0 && heights[r][c] <= heights[r-1][c] && !pacific[r-1][c])
        {
            dfsP(heights, pacific, r-1, c);
        }
        if (r + 1 < heights.size() && heights[r][c] <= heights[r+1][c] && !pacific[r+1][c])
        {
            dfsP(heights, pacific, r+1, c);
        }
        if (c - 1 >= 0 && heights[r][c] <= heights[r][c-1] && !pacific[r][c-1])
        {
            dfsP(heights, pacific, r, c-1);
        }
        if (c + 1 < heights[0].size() && heights[r][c] <= heights[r][c+1] && !pacific[r][c+1])
        {
            dfsP(heights, pacific, r, c+1);
        }
        return;
    }
};
