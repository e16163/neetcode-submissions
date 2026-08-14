class Solution {
public:
    bool isHappy(int n) {
        map<int, int> nums;
        nums[n]++;
        while (n != 1)
        {
            string s = to_string(n);
            n = 0;
            for (char c: s)
            {
                n += (c - '0') * (c - '0');
            }
            
            if (nums[n] > 0 && n != 1)
            {
                return false;
            }
            nums[n]++;
        }
        return true;

    }
};
