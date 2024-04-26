class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int ans=INT_MAX;
        vector<vector<int>> memoization(grid.size()+1,vector<int>(grid.size()+1,0)); 
        for(int i=0;i<grid[0].size();i++)
        {   
            ans=min(ans,dp(grid,0,i,memoization));
        }
        return ans;
    }

    int dp(vector<vector<int>>& grid,int row,int col,vector<vector<int>>& memoization){
        if(col<0 || col>=grid[0].size())
            return 100000;

        if(row==grid.size()-1)
            return grid[row][col];

        if(memoization[row][col]!=0)
            return memoization[row][col];

        int ans=INT_MAX;
        for(int i=0;i<grid[0].size();i++){
            if(i==col)
                continue;
            ans=min(ans,grid[row][col]+dp(grid,row+1,i,memoization));
        }
        return memoization[row][col]=ans;
    }
};