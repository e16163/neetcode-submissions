class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int left = 0;
        int right = (n * m) - 1;
        int cells = n * m;
        int mid = cells/2;
        while (cells>0)
        {
            mid = (right + left + 1)/2;
            cout<<mid<<endl;
            int row = mid/m;
            int col = mid%m;
            cout<<row<<", "<<col<<endl;
            if (target > matrix[row][col])
            {
                left = mid + 1;
            }
            else if (target < matrix[row][col])
            {
                right = mid - 1;
            }
            else if (target == matrix[row][col])
            {

                return true;
            }
            cells = right - left + 1;
        }
        return false;
    }
};
