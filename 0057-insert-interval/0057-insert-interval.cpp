class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size()==0) return {newInterval};
        vector<vector<int>> nonMerged;
        int flag = 0;
        for(int i=0;i<=intervals.size();i++) {
            if((i==intervals.size() || intervals[i][0]>=newInterval[0]) && !flag) {
                nonMerged.push_back(newInterval);
                flag = 1;
            } 
            if(i<intervals.size()) nonMerged.push_back(intervals[i]);
        }
        vector<vector<int>> ans;
        int lower = nonMerged[0][0];
        int upper = nonMerged[0][1];
        for(int i=0;i<nonMerged.size();i++) {
            int newLower = nonMerged[i][0];
            int newUpper = nonMerged[i][1];
            if(newLower>upper) {
                ans.push_back({lower,upper});
                lower = newLower;
            }
            upper = max(newUpper,upper);
        }
        ans.push_back({lower,upper});
        return ans;
    }
};


/*

clarifying qns

1. int no doubles? yes
2. ascending by start ? yes
3. if start is same then no specific ordering in end? wont happen 
4. if intervals are empty then the only insert interval will be the answer
5. start<=end


Ex:
   
2   8
10  14
18  20
22  25


insert => 13  17


2   8
10  20
22  25

Approach: 
1. create new ans of vector<vector<int>>
2. iterate intervals and keep adding to the ans as long as the starti < insertStart
    if equal then if endi>=insertEnd then keep adding
                    else insert the interval and then continue with the remaining 
                    intervals but while merging together

log (n) + O(n) ~ O(n)
O(n)
*/