class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str(n * 2, ' ');
        stack<char> paren;
        generate(ans, str, paren, 0, 0, n);
        return ans;

        
    }
    void generate(vector<string>& ans, string& str, stack<char> paren, int count, int i, int n)
    {
        if (i >= n * 2)
        {
            ans.push_back(str);
            return;
        }
        //add (
        if (count < n)
        {
            str[i] = '(';
            paren.push('(');
            generate(ans, str, paren, count + 1, i + 1, n);
            paren.pop();
            
        }
        if (!paren.empty())
        {
            str[i] = ')';
            paren.pop();
            
            generate(ans, str, paren, count, i + 1, n);
        }
        
        
        

    }
};
