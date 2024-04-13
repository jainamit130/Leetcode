class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(points.begin(),points.end());
        int a=points[0][0];
        int b=a+w;
        int ans=1;
        for(auto p:points){
            if(a<=p[0] && p[0]<=b)
                continue;
            else {
                ans++;
                a=p[0];
                b=p[0]+w;
            }
        }
        return ans;
    }
};