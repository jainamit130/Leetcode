class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        int n = original.size();
        int ans = INT_MAX;
        for(int i=1;i<n;i++) {
            int diff = original[i]-original[i-1];
            int prevLowerBound = bounds[i-1][0];
            int prevUpperBound = bounds[i-1][1];
            int currLowerBound = bounds[i][0];
            int currUpperBound = bounds[i][1];
            int newPrevL = prevLowerBound+diff;
            int newPrevU = prevUpperBound+diff;
            int common = min(newPrevU,currUpperBound) - max(newPrevL,currLowerBound) + 1;
            if(common<=0) return 0;
            ans = min(ans,common);
            bounds[i][0] = max(newPrevL,currLowerBound);
            bounds[i][1] = min(newPrevU,currUpperBound);
        }
        return ans;
    }
};


/*

57 55 75
 -2  20

58  104
43  60
58  60

63  80
18  67
63  67

*/