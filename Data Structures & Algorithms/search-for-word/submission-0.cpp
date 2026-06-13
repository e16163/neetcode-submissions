class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool ans = false;
        string path;
        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[0].size(); c++) 
            {
                search(board, path, word, r, c, ans);
                if (ans) return true; 
            }
        }
       
        return ans;
    }
    void search (vector<vector<char>>& board, string& path, string word, int x, int y, bool& ans)
    {
        if (x >= board.size() || y >= board[0].size())
        {
            return;
        }
        if (x < 0 || y < 0)
        {
            return;
        }
        if (board[x][y]=='1')
        {
            return;
        }
        //include
        path.push_back(board[x][y]);
        char ori = board[x][y];
        board[x][y] = '1';
        if (path==word)
        {
            ans = true;
            return;
        }
        //all 4 directions if possible
        search(board, path, word, x + 1, y, ans);
        search(board, path, word, x - 1, y, ans);
        search(board, path, word, x, y + 1, ans);
        search(board, path, word, x, y - 1, ans);
        //no include
        path.pop_back();
        board[x][y] = ori;
    }
};
