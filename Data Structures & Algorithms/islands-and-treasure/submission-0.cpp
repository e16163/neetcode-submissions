class Solution {
public:
    const int INF = 2147483647;
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int rows = grid.size();
        int cols = grid[0].size();
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j]==0)
                {
                    vector<vector<bool>> visited(rows, vector<bool>(cols, false));        
                    int distance = 0;
                    bfs(grid, q, visited, i, j, distance);
                }
            }
        }

    }
    void bfs (vector<vector<int>>& grid, queue<pair<int, int>>& q, vector<vector<bool>>& visited, int i, int j, int distance)
        {
            q.push({i, j});
            visited[i][j] = true;
            while (!q.empty())
            {
                int length = q.size();
                for (int k = 0; k < length; k++)
                {
                    pair<int, int> p = q.front();
                    q.pop();
                    // FIX 1: Extract the coordinates from p!
                    int r = p.first;
                    int c = p.second;

                    // Only update if the new distance found is shorter than what's there
                    if (distance < grid[r][c]) {
                        grid[r][c] = distance;
                    }

                    // FIX 2: Use 'r' and 'c' for checking neighbors instead of 'i' and 'j'
                    if (r - 1 >= 0 && grid[r-1][c] != -1 && !visited[r-1][c]) {
                        q.push({r - 1, c});
                        visited[r-1][c] = true;
                    }
                    if (r + 1 < grid.size() && grid[r+1][c] != -1 && !visited[r+1][c]) {
                        q.push({r + 1, c});
                        visited[r+1][c] = true;
                    }
                    if (c - 1 >= 0 && grid[r][c-1] != -1 && !visited[r][c-1]) {
                        q.push({r, c - 1});
                        visited[r][c-1] = true;
                    }
                    if (c + 1 < grid[0].size() && grid[r][c+1] != -1 && !visited[r][c+1]) {
                        q.push({r, c + 1});
                        visited[r][c+1] = true;
                    }
                }
                distance++;
            }
        }
    
};
