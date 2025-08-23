class Solution {
    public int minimumArea(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int minHor=n;
        int maxHor=0;
        int minVer=m;
        int maxVer=0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==1) {
                    minHor = Math.min(minHor,j);
                    minVer = Math.min(minVer,i);
                    maxHor = Math.max(maxHor,j);
                    maxVer = Math.max(maxVer,i);
                }
            }
        }

        return (maxHor-minHor+1)*(maxVer-minVer+1);
    }
}