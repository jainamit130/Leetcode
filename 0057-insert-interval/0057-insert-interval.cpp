class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        ans.push_back(intervals[0]); 
        int j=0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=ans[j][1]){
                int a=ans[j][0];
                int b=max(intervals[i][1],ans[j][1]);
                ans.pop_back();
                ans.push_back({a,b});
            }else { 
                ans.push_back(intervals[i]);
                j++;
            }
        }
        return ans;
    }
};