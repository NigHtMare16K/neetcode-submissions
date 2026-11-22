class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_vol = 0;
        int i = 0;
        int j = height.size() - 1;

        while(i<j){
            int currheight = min(height[i],height[j]);
            int size = j-i;
            int area = size*currheight;
            max_vol = max(area,max_vol);

            if(height[i]<height[j]){
                i++;
            }else{
                j--;
            }
        }

        return max_vol;
    }
};
