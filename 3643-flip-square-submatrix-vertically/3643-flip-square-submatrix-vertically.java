class Solution {
    public int[][] reverseSubmatrix(int[][] grid, int x, int y, int k) {
        int m = grid.length;
        int n = grid[0].length;
        for(int col=y;col<y+k;col++) {
            int i = x;
            int j = x+k-1;
            while(i<j) {
                int val1 = grid[i][col];
                grid[i][col] = grid[j][col];
                grid[j][col] = val1;
                i++;j--;
            }
        }
        return grid;
    }
}