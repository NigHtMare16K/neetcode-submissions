class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0;
        
        while(i<matrix[0].size()){
            int s = 0;
            int e = matrix.size()-1;

            if(target <= matrix[e][i]){
                while(s<=e){
                    int mid = s + (e-s)/2;
                    int num = matrix[mid][i];
                    if(num == target){
                        return true;
                    }else if(target < num){
                        e = mid -1;
                    }else{
                        s = mid + 1;
                    }
                }
            }

            i++;
        }

        return false;
    }
};
