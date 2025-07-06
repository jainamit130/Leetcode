class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int result = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j]!=0)
                    result = max(result, collect(i, j, grid));
            }
        }
        return result;
    }

    int collect(int row, int col, vector<vector<int>>& grid) {
        if (row >= grid.size() || col >= grid[0].size() || row < 0 || col < 0)
            return 0;

        if (grid[row][col] == 0)
            return 0;

        int t = grid[row][col];
        grid[row][col] = 0;
        int ans = t + max(collect(row + 1, col, grid),
                          max(collect(row - 1, col, grid),
                              max(collect(row, col - 1, grid),
                                  collect(row, col + 1, grid))));
        grid[row][col] = t;
        return ans;
    }
};

/*

0   6   0
5   8   7
0   9   0

*/