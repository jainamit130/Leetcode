class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        vector<vector<int>> sortedHeights(101,vector<int>());

        for(auto coordinates:rectangles)
            sortedHeights[coordinates[1]].push_back(coordinates[0]);
        
        for (int i=1;i<101;i++) sort(sortedHeights[i].begin(),sortedHeights[i].end());

        vector<int> ans(points.size());
        for(int i=0;i<points.size();i++){
            int subAns=0;
            for(int j=points[i][1];j<101;j++){
                subAns+=sortedHeights[j].size()-(lower_bound(sortedHeights[j].begin(),sortedHeights[j].end(),points[i][0])-sortedHeights[j].begin());
            }
            ans[i]=subAns;
        }
        return ans;
    }
};