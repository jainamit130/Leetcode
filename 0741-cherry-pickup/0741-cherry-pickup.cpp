class Solution {
public:
    vector<vector<int>> dir = { {0, 1}, {1, 0} };

    vector<vector<vector<int>>> memo;

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        memo.assign(n, vector<vector<int>>(n, vector<int>(n, -1)));
        int result = max(0, solve(0, 0, 0, grid));
        return result;
    }

    bool isValid(int row, int col, int n) {
        return row >= 0 && row < n && col >= 0 && col < n;
    }

    int solve(int row1, int col1, int col2, vector<vector<int>>& grid) {
        int n = grid.size();
        int row2 = row1 + col1 - col2;

        if (!isValid(row1, col1, n) || !isValid(row2, col2, n) ||
            grid[row1][col1] == -1 || grid[row2][col2] == -1) {
            return INT_MIN;
        }

        if (row1 == n - 1 && col1 == n - 1) {
            return grid[row1][col1];
        }

        if (memo[row1][col1][col2] != -1) {
            return memo[row1][col1][col2];
        }

        int cherries = grid[row1][col1];
        if (col1 != col2) {
            cherries += grid[row2][col2];
        }

        int maxCherries = INT_MIN;
        for (auto& d1 : dir) {
            int newRow1 = row1 + d1[0];
            int newCol1 = col1 + d1[1];
            for (auto& d2 : dir) {
                int newRow2 = row2 + d2[0];
                int newCol2 = col2 + d2[1];
                maxCherries = max(maxCherries, solve(newRow1, newCol1, newCol2, grid));
            }
        }

        cherries += maxCherries;

        return memo[row1][col1][col2] = cherries;
    }
};
