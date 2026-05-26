class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operands; 
        for (int i = 0; i<tokens.size(); i++)
        {
            if (tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/")
            {
                string operation = tokens[i];
                int op1 = operands.top();
                operands.pop();
                int op2 = operands.top();
                operands.pop();
                int ans;
                if (operation=="+")
                {
                    ans = op1 + op2;
                }
                else if (operation == "*")
                {
                    ans = op1*op2;
                }
                else if (operation=="/")
                {
                    ans = op2/op1;
                }
                else if (operation == "-")
                {
                    ans = op2-op1;
                }
                operands.push(ans);


            }
            else
            {
                int op = std::stoi(tokens[i]);
                operands.push(op);
            }

        }
        return operands.top();
    }
};
