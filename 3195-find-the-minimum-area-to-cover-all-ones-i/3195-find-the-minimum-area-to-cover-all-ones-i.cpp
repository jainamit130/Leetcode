class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int minI=INT_MAX;int minJ=INT_MAX;
        int maxI=INT_MIN;int maxJ=INT_MIN;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    minI=min(minI,i);
                    minJ=min(minJ,j);
                    maxI=max(maxI,i);
                    maxJ=max(maxJ,j);
                }
            }
        }
        return (maxI-minI+1)*(maxJ-minJ+1);
    }
};