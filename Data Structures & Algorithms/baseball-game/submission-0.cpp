class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> ops;
        for (int i = 0; i < operations.size(); i++) {
            string s = operations[i];
            if (s.size() > 1) {
                ops.push(stoi(s));
            }
            else {
                if (s == "+") {
                    int first = ops.top();
                    ops.pop();
                    int second = ops.top();
                    ops.pop();
                    int add = first + second;
                    ops.push(second);
                    ops.push(first);
                    ops.push(add);
                }
                else if (s == "D") {
                    int prev = ops.top();
                    ops.push(prev * 2);
                }
                else if (s == "C") {
                    ops.pop();
                }
                else {
                    ops.push(stoi(s));
                }
            }
        }
        int score = 0;
        while (!ops.empty()) {
            score += ops.top();
            ops.pop();
        }
        return score;
    }
};