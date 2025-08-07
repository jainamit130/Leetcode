class Solution {
    Integer[][] dp;
    public Map<Integer,List<List<Integer>>> mp = Map.of(
        0,List.of(List.of(1,1),List.of(1,-1),List.of(1,0)),
        1,List.of(List.of(0,1),List.of(-1,1),List.of(1,1))
    );
    int n;
    public int maxCollectedFruits(int[][] fruits) {
        n = fruits.length;
        dp = new Integer[n][n]; 
        int ans = solve(0,n-1,0,fruits) + solve(n-1,0,1,fruits);
        for(int i=0;i<n;i++) ans+=fruits[i][i];
        return ans;
    }

    boolean isValid(int row,int col) {
        return row>=0 && row<n && col>=0 && col<n;
    }

    int solve(int row,int col,int child,int[][] fruits) {
        if(row==n-1 && col==n-1) return 0;
        if((child==0 && col<=row) || (child==1 && row<=col)) return Integer.MIN_VALUE;
        if (dp[row][col] != null) return dp[row][col];

        int ans = 0;
        List<List<Integer>> dir = mp.get(child);
        for(int i=0;i<dir.size();i++) {
            int newRow = row + dir.get(i).get(0);
            int newCol = col + dir.get(i).get(1);
            if(!isValid(newRow,newCol)) continue;
            ans = Math.max(ans , fruits[row][col] + solve(newRow,newCol,child,fruits));
        }
        return dp[row][col]=ans;
    }
}