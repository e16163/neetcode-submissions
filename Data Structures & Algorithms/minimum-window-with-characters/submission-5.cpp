class Solution {
public:
    string minWindow(string s, string t) {
        
        int start = 0; 
        map<char, int> sub;
        map<char, int> check;
        map<char, int> count;
        int shortest = 1000;
        int end = 0;
        string ans;
        int need = 0;
        int have = 0;
        for (int i = 0; i<t.length(); i++)
        {
            if (check[t[i]]==0)
            {
                need++;
            }
            check[t[i]]++;
            
        }
        while (end<s.length())
        {
            
            
           count[s[end]]++;
            if (check.count(s[end]) > 0 && count[s[end]] == check[s[end]])
            {
                have++;
            } 
            if (check.count(s[start]) == 0)
            {
                
                while (start < s.length()&&check.count(s[start]) == 0)
                {
                    
                    start++;
                    
                }
                
                
            }
            else
            {
                if (count[s[start]]>check[s[start]])
                {
                    while (count[s[start]]>check[s[start]]||check[s[start]] == 0)
                    {
                        
                        count[s[start]]--;
                        if (count[s[start]]<check[s[start]])
                        {
                            have--;
                        }
                        start++;
                        
                    }
                }
            }
            cout<<"count: ";
            for (auto pair: count)
            {
                cout<<pair.first<<" ";
            }
            cout<<endl;
            cout<<"check: ";
            for (auto x: check)
            {
                cout<<x.first<<" ";
            }
            cout<<endl;

            cout<<s.substr(start, end-start+1)<<endl;
            cout<<"have: "<<to_string(have)<<", need: "<<to_string(need)<<endl;
            if (have==need)
            {
                int length = end-start+1;
                shortest = min(length, shortest);
                if (shortest==length)
                {
                    ans = s.substr(start, length);
                }
            }

            end++;
            
            
        }
        return ans;

    }
};
