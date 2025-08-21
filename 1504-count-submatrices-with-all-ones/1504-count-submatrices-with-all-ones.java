class Solution {
    public int numSubmat(int[][] mat) {
        int ans = 0;
        int[][] dp = new int[mat.length][mat[0].length];
        for(int i=0;i<mat.length;i++) {
            int cons1 = 0;
            for(int j=0;j<mat[0].length;j++) {
                if(mat[i][j]==1) {
                    cons1++;
                    ans += cons1;
                    dp[i][j]=cons1;
                    int width = cons1;
                    for(int k=i-1;k>=0;k--) {
                        if(mat[k][j]==0) break;
                        width = Math.min(width,dp[k][j]);
                        ans += width;
                    }
                } else {
                    cons1=0;
                }
            }
        }
        return ans;
    }
}