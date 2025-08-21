class Solution {
    public int numSubmat(int[][] mat) {
        int m = mat.length, n = mat[0].length;
        int ans = 0;
        int[][] width = new int[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    width[i][j] = (j == 0 ? 1 : width[i][j-1] + 1);

                    int minWidth = width[i][j];
                    for (int k = i; k >= 0 && minWidth > 0; k--) {
                        minWidth = Math.min(minWidth, width[k][j]);
                        ans += minWidth;
                    }
                }
            }
        }
        return ans;
    }
}



/*


0   1   1   0
0   1   1   1
1   1   1   0

ans = 0 + 1 + 2 + 3 + 1 + 3 + 5 + 0 + 0 + 3 + 6

horizontal
0   2   1   0   0
0   0   2   1   0
3   2   1   0   0
0   0   0   0   0

vertical
0   0   1   0   0
0   2   2   1   0
1   1   1   0   0
0   0   0   0   0




*/