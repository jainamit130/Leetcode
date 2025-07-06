class Solution {
    int[][] grid;
    public int countUnguarded(int m, int n, int[][] guards, int[][] walls) {
        grid = new int[m][n];
        boolean[] colGuard = new boolean[n];
        boolean[] revColGuard = new boolean[n];
        
        for (int[] coordinates : guards) {
            grid[coordinates[0]][coordinates[1]] = 1;
        }

        for (int[] coordinates : walls) {
            grid[coordinates[0]][coordinates[1]] = 2;
        }

        for (int i = 0; i < m; i++) {
            int revI = m - i - 1;
            boolean[] isGuarded = {false};
            boolean[] isRevGuarded = {false};
            for (int j = 0; j < n; j++) {
                int revJ = n - j - 1;
                markCell(i, j, colGuard, isGuarded);
                markCell(revI, revJ, revColGuard, isRevGuarded);
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    ans++;
                }
            }
        }
        return ans;
    }

    private void markCell(int i, int j, boolean[] colGuard, boolean[] isGuarded) {
        if ((isGuarded[0] || colGuard[j]) && grid[i][j] == 0) {
            grid[i][j] = 3;
        }

        if (grid[i][j] == 1) {
            colGuard[j] = true;
            isGuarded[0] = true;
        } else if (grid[i][j] == 2) {
            colGuard[j] = false;
            isGuarded[0] = false;
        }
    }
}
