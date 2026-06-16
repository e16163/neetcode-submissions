class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        vector<vector<vector<int>>> adjacent(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(4, 0)));
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (i - 1 >= 0)
                {
                    adjacent[i][j][0] = grid[i - 1][j];
                }
                if (j + 1 < grid[0].size())
                {
                    adjacent[i][j][1] = grid[i][j+1];
                }
                if (i + 1 < grid.size())
                {
                    adjacent[i][j][2] = grid[i+1][j];
                }
                if (j - 1 >= 0)
                {
                    adjacent[i][j][3] = grid[i][j-1];
                }
                
            }
        }
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j]==1 && visited[i][j]==0)
                {
                    int area = 0;
                    dfs(grid, visited, adjacent, area, i, j);
                    ans = max(ans, area);
                }
            }
        }
        return ans;
        

    }
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, vector<vector<vector<int>>>& adjacent, int& num, int i, int j)
    {
        
        visited[i][j] = 1;
        num++;
        if (adjacent[i][j][0]==1 && visited[i-1][j]==0)
        {
            
            dfs(grid, visited, adjacent, num, i - 1, j);
        }
        if (adjacent[i][j][1]==1 && visited[i][j+1]==0)
        {
           
            dfs(grid, visited, adjacent, num, i, j + 1);
        }
        if (adjacent[i][j][2]==1 && visited[i+1][j]==0)
        {
           
            dfs(grid, visited, adjacent, num, i + 1, j);
        }
        if (adjacent[i][j][3]==1 && visited[i][j - 1]==0)
        {
            
            dfs(grid, visited, adjacent, num, i, j - 1);
        }
        return;
    }
};
