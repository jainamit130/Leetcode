class Solution {
public:
    int m,n;
    int dp[501][501][4][2][2];
    unordered_map<int,vector<int>> dirMp = { {0,{-1,1}}, {1,{1,1}}, {2,{1,-1}}, {3,{-1,-1}} };
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int ans = 0;
        m = grid.size();
        n = grid[0].size();
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==1) {
                    for(int k=0;k<4;k++) {
                        ans = max(ans,1+solve(grid, i,j,k,0,1));
                    }
                }
            }
        }
        return ans;
    }

    bool isValid(int row,int col,vector<vector<int>>& grid,int order) {
        return row>=0 && row<m && col>=0 && col<n && ((grid[row][col]==2 && order) || (!grid[row][col] && !order));
    }

    int solve(vector<vector<int>>& grid,int row,int col,int dir,int turn,int order) {
        if(dp[row][col][dir][turn][order]!=-1) return dp[row][col][dir][turn][order];
        int length = 0;
        
        // either to go forward
        int newRow = row+dirMp[dir][0];
        int newCol = col+dirMp[dir][1];
        if(isValid(newRow,newCol,grid,order)) length = max(length,1+solve(grid,newRow,newCol,dir,turn,!order));

        // or to change direction
        if(!turn) {
            int newDir = (dir+1)%4;
            int newRow = row+dirMp[newDir][0];
            int newCol = col+dirMp[newDir][1];
            if(isValid(newRow,newCol,grid,order)) length = max(length,1+solve(grid,newRow,newCol,newDir,1,!order));
        }
        return dp[row][col][dir][turn][order]=length;
    }
};


/*
diagonal directions
1   1   
-1  1


States

row
col
dir
turn
order

*/