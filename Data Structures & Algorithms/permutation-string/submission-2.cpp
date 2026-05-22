class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char, int> perm;
        int start = 0; 
        int length = 0;
        map<char,int> sub;
        for (int i = 0; i<s1.length(); i++)
        {
            perm[s1[i]]++;
            
        }
        for (int end = 0; end<s2.length(); end++)
        {
            char next = s2[end];
            sub[next]++;
            if (end-start+1>s1.length())
            {
                sub[s2[start]]--;
                if (sub[s2[start]]==0)
                {
                    sub.erase(s2[start]);
                }
                start++;
            }
            if (sub==perm)
            {
                return true;
            }
        }
        return false;
    }
};
