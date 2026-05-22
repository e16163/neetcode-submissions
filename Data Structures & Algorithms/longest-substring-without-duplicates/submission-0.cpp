class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        
        if (s.length()==0) 
        {
            return 0;
        }
        map<char, int> sub; 
        int ans = 0;
        for (int end = 0; end<s.length(); end++)
        {
            char next = s[end];
            sub[next]++;
            while (sub[next]>1)
            {
                sub[s[start]]--;
                start++;
            }
            ans = max(ans, (end-start)+1);
        }
        return ans;
    }
};
