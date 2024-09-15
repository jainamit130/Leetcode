class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        return solve(grid, 0, 0, visited, health);
    }

    bool solve(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& visited, int health) {
        int m = grid.size();
        int n = grid[0].size();

        if (row < 0 || row >= m || col < 0 || col >= n || visited[row][col]) {
            return false;
        }
        if (grid[row][col] == 1) {
            health -= 1;
        }
        if (health <= 0) {
            return false;
        }
        if (row == m - 1 && col == n - 1) {
            return health > 0;
        }

        visited[row][col] = 1;

        bool canReach = solve(grid, row + 1, col, visited, health) ||
                        solve(grid, row - 1, col, visited, health) ||
                        solve(grid, row, col + 1, visited, health) ||
                        solve(grid, row, col - 1, visited, health);

        visited[row][col] = 0;

        return canReach;
    }
};