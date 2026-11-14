class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        for (int i = 0; i < 200; i++) {
            if (i >= strs[0].size()) {
                break;
            }
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].size()) {
                    return prefix;
                }
                if (strs[j][i] != c) {
                    return prefix;
                }
            }
            prefix.push_back(c);
        }
        return prefix;
    }
};