class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        map<int, int> rows;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j<n; j++)
            {
                board[i] += '.';
            }
        }
        backtrack(ans, board, rows, n, 0, 0);
        return ans;
    }
    void backtrack(vector<vector<string>>& ans, vector<string>&board, map<int, int>& rows, int n, int i, int j)
    {
        if (i >= n)
        {
            ans.push_back(board);
            return;
        }
        //check row
        for (int j = 0; j < n; j++)
        {
            if (rows[j]==0 && diagonal(board, j, i, n))
            {
                board[j][i] = 'Q';
                rows[j] = 1;
                backtrack(ans, board, rows, n, i + 1, j);
                rows[j] = 0;
                board[j][i] = '.';
            }
        }
        
        
        

    }
    bool diagonal(vector<string> board, int j, int i, int n)
    {
        int copyi = i;
        int copyj = j;
        while (i >= 0 && j >= 0)
        {
            if (board[j][i]=='Q')
            {
                return false;
            }
            i--;
            j--;
        }
        while (copyj < n && copyi >= 0)
        {
            if (board[copyj][copyi]=='Q')
            {
                return false;
            }
            copyi--;
            copyj++;
        }
        return true;
    }
};
