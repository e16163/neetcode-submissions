class Solution {
public:
vector<vector<int>> res;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        backtrack(candidates, target, curr, 0);
        return res;
    }
    void backtrack(vector<int>& candidates, int target,  vector<int>& curr, int i)
    {
        if (target==0)
        {
            res.push_back(curr);
            return;
        }
        if (target < 0 || i >= candidates.size())
        {
            return;
        }
        curr.push_back(candidates[i]);
        backtrack(candidates, target - candidates[i], curr, i + 1);
        int j = i;
        
        curr.pop_back();
        while (j + 1 < candidates.size() && candidates[j]==candidates[j+1])
        {
            j++;
        }
        i = j;
        backtrack(candidates, target, curr, i + 1);

        
        
    }
};
