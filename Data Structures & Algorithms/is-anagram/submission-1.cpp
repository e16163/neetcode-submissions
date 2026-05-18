class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> letters;
        map<char, int> letters2;
        for (int i = 0; i<s.length(); i++)
        { 
            letters[s[i]]++;
        }
        for (int i = 0; i<t.length(); i++) 
        {
            letters2[t[i]]++;
        }
        if (s.length() != t.length()) return false;
        for (auto i: letters)
        {
            if (letters[i.first]!=letters2[i.first])
            {
                return false;
            }
        }
        return true;
    }
};