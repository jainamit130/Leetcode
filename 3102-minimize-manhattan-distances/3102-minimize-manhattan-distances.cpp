class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
        int maxSum=INT_MIN;
        int minSum=INT_MAX;
        int maxDiff=INT_MIN;
        int minDiff=INT_MAX;
        for(auto p:points){
            int x=p[0];
            int y=p[1];
            maxSum=max(maxSum,x+y);
            minSum=min(minSum,x+y);
            maxDiff=max(maxDiff,x-y);
            minDiff=min(minDiff,x-y);
        }
        return min(maxSum-minSum,maxDiff-minDiff);
    }
};

/*


[[3,10],[5,15],[10,2],[4,4]]



*/