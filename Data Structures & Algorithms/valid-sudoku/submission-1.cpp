class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<map<char,int>> rows;
        vector<map<char,int>> cols;
        rows.resize(9);
        cols.resize(9);
        map<char,int> topleft;
        map<char,int> topmid;
        map<char,int> topright;
        map<char,int> midleft;
        map<char,int> midmid;
        map<char,int> midright;
        map<char,int> botleft;
        map<char,int> botmid;
        map<char,int> botright;
        for (int i = 0; i<9; i++)
        {
            for (int j = 0; j<9; j++)
            {
                //cout<<board[i][j]<<" ";
                if (board[i][j]!='.')
                {
                    rows[i][board[i][j]]++;
                    cols[j][board[i][j]]++; 
                    cout<<board[i][j]<<" "<<i<<" . "<<j<<endl;
                    if (rows[i][board[i][j]]>1)
                    {
                        return false;
                    }
                    if (cols[j][board[i][j]]>1)
                    {
                        return false;
                    }
                    if (i<3 && j<3)
                    {
                        topleft[board[i][j]]++;
                        if (topleft[board[i][j]]>1)
                        {
                            return false;
                        }
                    }
                    else if (i<3 && j<6)
                    {
                        topmid[board[i][j]]++;
                        if (topmid[board[i][j]]>1)
                        {
                            return false;
                        }

                    }
                    else if (i<3 && j<9)
                    {
                        topright[board[i][j]]++;
                        if (topright[board[i][j]]>1)
                        {
                            return false;
                        }

                    }
                    else if (i<6 && j<3)
                    {
                        midleft[board[i][j]]++;
                        if (midleft[board[i][j]]>1)
                        {
                            return false;
                        }
                    }
                    else if (i<6 && j<6)
                    {
                        midmid[board[i][j]]++;
                        if (midmid[board[i][j]]>1)
                        {
                            return false;
                        }
                    }
                    else if (i<6 && j<9)
                    {
                        midright[board[i][j]]++;
                        if (midright[board[i][j]]>1)
                        {
                            return false;
                        }
                    }
                    else if (i<9 && j<3)
                    {
                        botleft[board[i][j]]++;
                        if (botleft[board[i][j]]>1)
                        {
                            return false;
                        }
                    }
                    else if (i<9 && j<6)
                    {
                        botmid[board[i][j]]++;
                        if (botmid[board[i][j]]>1)
                        {
                            return false;
                        }
                    }
                    else if (i<9 && j<9)
                    {
                        botright[board[i][j]]++;
                        if (botright[board[i][j]]>1)
                        {
                            return false;
                        }
                    }
                }
                
                
            }
            //cout<<endl;
        }
        return true;
    }
};
