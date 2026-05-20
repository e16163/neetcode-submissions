class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.length()-1;
        while (start<end)
        {
            char c1 = s[start];
            char c2 = s[end];
            
            if (!isalnum(c2)||!isalnum(c1))
            {
                if (!isalnum(c1))
                {
                    start++;
                } 
                if (!isalnum(c2))
                {
                    end--;
                } 
                continue;
            }
            if ((char)tolower(c1)!=(char)tolower(c2))
            {
                cout<<c1<<" "<<c2<<endl;
                return false;
            }
            else
            {
                start++;
                end--;
            }
        }
        return true;
        
        
    }
};
