class Solution {
public:
    unordered_map<int, vector<int>> dirMp = {
        {1, {-1, 1}}, {2, {1, 1}}, {3, {1, -1}}, {4, {-1, -1}}};
    
    unordered_map<int, int> clockwise = {{1, 2}, {2, 3}, {3, 4}, {4, 1}};
    int dp[501][501][2][4][2];
    int m, n;

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int ans = 0;
        m = grid.size();
        n = grid[0].size();
        memset(dp , -1 ,sizeof(dp));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {  
                    for (int k = 1; k <= 4; k++) { 
                        ans = max(ans,1+ solve(grid, i+dirMp[k][0], j+dirMp[k][1], 0, k, 1));  
                    }
                }
            }
        }
        
        return ans;
    }

    bool isValid(int row, int col) {
        return row >= 0 && row < m && col >= 0 && col < n;
    }

    int solve(vector<vector<int>>& grid, int row, int col, int turn, int dir, int shouldBe2) {
        if(!isValid(row,col)) return 0;
        if(shouldBe2 && grid[row][col]!=2) return 0;
        if(!shouldBe2 && grid[row][col]!=0) return 0;
        if(dp[row][col][turn][dir-1][shouldBe2]!=-1) return dp[row][col][turn][dir-1][shouldBe2];
        int ans = 0; 
        
        int newRow = row + dirMp[dir][0];
        int newCol = col + dirMp[dir][1];
        
        ans = max(ans, 1 + solve(grid, newRow, newCol, turn, dir, !shouldBe2));

        if (!turn) {
            vector<int> newDir = dirMp[clockwise[dir]];
            ans = max(ans, 1 + solve(grid, row + newDir[0], col + newDir[1], 1, clockwise[dir], !shouldBe2));
        }
        
        return dp[row][col][turn][dir-1][shouldBe2]=ans;
    }
};


/*

2,1,2,2],[2,0,1,0],[2,2,2,2],[0,0,0,0],[2,2,2,2


2   1   2   2
2   0   1   0
2   2   2   2
0   0   0   0
2   2   2   2


2,2,0,2,0,2,0],[1,2,2,1,0,2,0

2   2   0   2   0   2   0
1   2   2   1   0   2   0

4,1 -> 5,0 => 6,-1 => 6%5,-1%4 => 1,3

4,3 -> 5,4 => 1,0


*/