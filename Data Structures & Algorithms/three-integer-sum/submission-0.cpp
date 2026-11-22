class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            int j = i+1;
            int k = nums.size()-1;
            int target = -(nums[i]); 

            while(j<k){
                int sum =  nums[j] + nums[k];
                if(sum == target){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(j < k && nums[j-1] == nums[j]){
                        j++;
                    }
                    while(j < k && nums[k+1] == nums[k]){
                        k--;
                    }
                }else if(sum>target){
                    k--;
                }else{
                    j++;
                }
            }
        }

        return ans;
    }
};
