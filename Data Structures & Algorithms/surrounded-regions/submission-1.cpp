class Solution {
public:
    void solve(vector<vector<char>>& board) {
        //can it go to an edge
        const int rows = board.size();
        const int cols = board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (board[i][j] == 'O' && !visited[i][j])
                {
                    bool edge = false;
                    vector<pair<int, int>> path;
                    dfs(board, visited, path, i, j, edge);
                    if (!edge)
                    {
                        for (pair p: path)
                        {
                            board[p.first][p.second] = 'X';
                            //cout<<p.first<<" "<<p.second<<endl;
                        }
                    }
                }
            }
        }
    }
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, vector<pair<int, int>>& path, int r, int c, bool& edge)
    {
        
        visited[r][c] = true;
        path.push_back({r, c});
        cout<<r + 1 <<" "<< c + 1<< endl;
        if (r == 0 || c == 0 || r == board.size()-1 || c == board[0].size()-1)
        {
            edge = true;
        }
        if (r - 1 >= 0 && board[r-1][c] == 'O' && !visited[r-1][c])
        {
            dfs(board, visited, path, r-1, c, edge);
        }
        if (r + 1 < board.size() && board[r+1][c] == 'O' && !visited[r+1][c])
        {
            dfs(board, visited, path, r+1, c, edge);
        }
        if (c - 1 >= 0 && board[r][c-1] == 'O' && !visited[r][c-1])
        {
            dfs(board, visited, path, r, c-1, edge);
        }
        if (c + 1 < board[0].size() && board[r][c+1] == 'O' && !visited[r][c+1])
        {
            dfs(board, visited, path, r, c+1, edge);
        }
        
        return;
    }
};
