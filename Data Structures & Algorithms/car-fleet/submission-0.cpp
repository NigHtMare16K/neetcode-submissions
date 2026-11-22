class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<vector<int>> ans;

        for(int i =0;i<position.size();i++){
            ans.push_back({position[i],speed[i]});
        }

        sort(ans.begin(), ans.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];
        });

        stack<double> st;

        for(int i=0;i<position.size();i++){
            double time = (double)(target-ans[i][0])/ans[i][1];
            if(i==0){
                st.push(time);
            }else{
                if(time<=st.top()){
                    continue;
                }else{
                    st.push(time);
                }
            }
        }

        int count = 0;
        while(!st.empty()){
            st.pop();
            count++;
        }

        return count;
    }
};
