class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](auto lhs,auto rhs){
            if(lhs[0]==rhs[0]){
                return lhs[1]<rhs[1];
            }
            return lhs[0]<rhs[0];
        });

        vector<vector<int>> ans;
        int i=0;
        while(i<intervals.size()){
            int startInterval=intervals[i][0];
            int endInterval=intervals[i][1];
            while(i+1<intervals.size() && endInterval>=intervals[i+1][0]){
                endInterval=max(intervals[i+1][1],endInterval);
                i++;
            }
            ans.push_back({startInterval,endInterval});
            i++;
        }
        return ans;
    }
};