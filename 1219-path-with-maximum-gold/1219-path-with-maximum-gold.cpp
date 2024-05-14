class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int result = 0;
        vector<vector<int>> dp(grid.size() + 1,vector<int>(grid[0].size() + 1, -1));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j]!=0)
                    result = max(result, collect(i, j, grid, dp));
            }
        }
        return result;
    }

    int collect(int row, int col, vector<vector<int>>& grid,
                vector<vector<int>>& dp) {
        if (row >= grid.size() || col >= grid[0].size() || row < 0 || col < 0)
            return 0;

        if (grid[row][col] == 0)
            return 0;

        if (dp[row][col] != -1)
            return dp[row][col];

        int t = grid[row][col];
        cout << row << " " << col << " " << t << endl;
        grid[row][col] = 0;
        
        int ans = t + max(collect(row + 1, col, grid, dp),
                          max(collect(row - 1, col, grid, dp),
                              max(collect(row, col - 1, grid, dp),
                                  collect(row, col + 1, grid, dp))));
        grid[row][col] = t;
        return dp[row][col] = ans;
    }
};

/*

0   6   0
5   8   7
0   9   0

*/