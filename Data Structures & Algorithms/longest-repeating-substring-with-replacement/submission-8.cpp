class Solution {
public:
    int characterReplacement(string s, int k) {
        int start = 0;
        map<char, int> freq;
        int common = 0;
        int ans = 0;
        for (int end = 0; end < s.length(); end++)
        {
            cout<<start<<", "<<end<<endl;
            int length = end - start + 1;
            char c = s[end];
            freq[c]++;
            if (freq[c] > common)
            {
                common = freq[c];
            }
            if (length - common <=k)
            {
                ans = max(length, ans);
                
            }
            else
            {
                freq[s[start]]--;
                
                start++;
            }
        }
        return ans;
    }
};
