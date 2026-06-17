class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        const int rows = grid.size();
        const int cols = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));        
        int time = 0;
        int fresh = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j]==2)
                {
                    q.push({i, j});
                }
                else if (grid[i][j]==1)
                {
                    fresh++;
                }
                
            }
        }
        //bfs
        while (!q.empty())
        {
            
            int length = q.size();

            for (int i = 0; i < length; i++)
            {
                int r = q.front().first;
                int c = q.front().second;
                visited[r][c] = true;
                q.pop();
                if (grid[r][c]==1)
                {
                    fresh--;
                    grid[r][c] = 2;
                }
                if (fresh==0)
                {
                    return time;
                }
                cout<<r+1<<", "<<c+1<<endl;
                cout<<"time: "<<time<<" |  fresh: "<<fresh<<endl;
                if (r - 1 >= 0 && grid[r-1][c]==1 && !visited[r-1][c])
                {
                    q.push({r-1, c});
                    visited[r-1][c] = true;
                }
                if (r + 1 < rows && grid[r+1][c]==1 && !visited[r+1][c])
                {
                    q.push({r+1, c});
                    visited[r+1][c] = true;
                }
                if (c - 1 >= 0 && grid[r][c-1]==1 && !visited[r][c-1])
                {
                    q.push({r, c-1});
                    visited[r][c-1] = true;
                }
                if (c + 1 < cols && grid[r][c+1]==1 && !visited[r][c+1])
                {
                    q.push({r, c+1});
                    visited[r][c+1] = true;
                }
            }
            time++;

        }
        if (fresh==0)
        {
            return time;
        }
        return -1;
        
    }
};
