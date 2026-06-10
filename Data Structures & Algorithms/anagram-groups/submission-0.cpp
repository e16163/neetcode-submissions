class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<map<char, int>, int> anagrams;
        map<map<char, int>, vector<string>> lists;
        for (int i = 0; i<strs.size(); i++)
        {
            string s = strs[i];
            map<char, int> m;
            for (int j = 0; j<strs[i].length(); j++)
            {
                m[s[j]]++;
            }
            anagrams[m]++;
            lists[m].push_back(s);
        }
        for (const auto& [ana, strings] : lists) 
        {
           ans.push_back(strings);
        }
        return ans;
    }
};
