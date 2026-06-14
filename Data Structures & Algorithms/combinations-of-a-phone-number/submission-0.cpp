class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> convert (10);
        vector<string> ans;
        string combo;
        convert[2] = "abc";
        convert[3] = "def";
        convert[4] = "ghi";
        convert[5] = "jkl";
        convert[6] = "mno";
        convert[7] = "pqrs";
        convert[8] = "tuv";
        convert[9] = "wxyz";
        if (digits.size()==0)
        {
            return {};
        }
        backtrack(digits, ans, convert, combo, 0);
        return ans;
    }
    void backtrack(string& digits, vector<string>& ans, vector<string>& convert, string combo, int i)
    {
        if (combo.length() == digits.length())
        {
            ans.push_back(combo);
            return;
        }
        string s = convert[digits[i] - '0'];
        for (char c: s)
        {
            backtrack(digits, ans, convert, combo + c, i + 1);
        }
    }
    
    
};
