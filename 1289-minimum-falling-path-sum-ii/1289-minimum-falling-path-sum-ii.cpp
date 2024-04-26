class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size()+1,vector<int>(grid[0].size()+1,INT_MAX));
        return dfs(0,grid,-1,dp);
    }

    int dfs(int row,vector<vector<int>>& grid,int prevCol,vector<vector<int>>& dp){
        if(row>=grid.size()){
            return 0;
        }

        if(dp[row][prevCol+1]!=INT_MAX){
            return dp[row][prevCol+1];
        }

        int result=INT_MAX;
        for(int col=0;col<grid[0].size();col++){
            if(prevCol==col)
                continue;
            result=min(result,grid[row][col]+dfs(row+1,grid,col,dp));
        }
        return dp[row][prevCol+1]=result;
    }
};


/*

*   *   *   *   *
-   -   -   -   -
*   *   *   *   *



*/