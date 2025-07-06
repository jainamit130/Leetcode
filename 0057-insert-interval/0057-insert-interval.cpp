class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size()==0) return {newInterval};
        vector<vector<int>> ans;
        int i=0;
        while(i<intervals.size()) {
            if(intervals[i][1]<newInterval[0]) ans.push_back(intervals[i]);
            else break;
            i++;
        }

        int lower = newInterval[0];
        int upper = newInterval[1];
        if(i<intervals.size()) lower = min(intervals[i][0],lower);
        while(i<intervals.size()) {
            int newLower = intervals[i][0];
            int newUpper = intervals[i][1];
            if(newLower>upper) {
                ans.push_back({lower,upper});
                lower = newLower;
            } 
            upper = max(upper,newUpper);
            i++;
        }
        ans.push_back({lower,upper});
        return ans;
    }
};