class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int i = 0;
        
        while (i < cols) {               // Fix 1: '<' instead of '<='
            int s = 0;
            int e = rows - 1;            // Fix 2: 'rows - 1' instead of 'rows'

            if (target <= matrix[e][i]) { // Only search if target can fit in this column
                while (s <= e) {
                    int mid = s + (e - s) / 2;
                    int num = matrix[mid][i];
                    
                    if (num == target) {
                        return true;
                    } else if (target < num) {
                        e = mid - 1;
                    } else {
                        s = mid + 1;
                    }
                }
            }
            i++;                         // Fix 3: Increment 'i' only once per iteration
        }

        return false;
    }
};

