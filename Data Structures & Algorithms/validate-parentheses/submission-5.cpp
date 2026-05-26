class Solution {
public:
    bool isValid(string s) {
        stack<char> add;
        if (s.length()%2!=0)
        {
            return false;
        }
        for (int i = 0; i<s.length(); i++)
        {
            if (s[i]=='(' || s[i] == '{' || s[i] == '[')
            {
                add.push(s[i]);
            }
            else
            {
                if (add.empty())
                {
                    return false;
                }
                if (s[i]==']')
                {
                    if (add.top()!='[')
                    {
                        return false;
                    }
                    else
                    {
                        add.pop();
                    }
                }
                else if (s[i]=='}')
                {
                    if (add.top()!='{'||add.empty())
                    {
                        return false;
                    }
                    else
                    {
                        add.pop();
                    }
                }
                else if (s[i]==')')
                {
                    if (add.top()!='('||add.empty())
                    {
                        return false;
                    }
                    else
                    {
                        add.pop();
                    }
                }
                
            }
        }
        if (add.empty())
        {
            return true;
        }
        return false;
        
    }
};
