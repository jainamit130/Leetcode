class Solution {
    public List<List<Integer>> shiftGrid(int[][] grid, int k) {
        int m = grid.length;
        int n = grid[0].length;
        int[][] visited = new int[m][n];
        int toProcess = m*n;
        int i = 0, j = 0;
        int element = grid[0][0];
        while(toProcess>0) {
            while(visited[i][j]==1) {
                j++;
                if(j==n) {
                    i = (i+1)%m;
                    j=0;
                }
                if(visited[i][j]==0) element = grid[i][j];
            }

            visited[i][j]=1;
            int startIndex = i * n + j;
            int newIndex = (startIndex + k) % (m * n);
            int newRow = newIndex / n;
            int newCol = newIndex % n;
            
            i = newRow; j = newCol;
            int temp = grid[i][j];
            grid[i][j] = element;
            toProcess--;
            if(visited[i][j]==1) {
                continue;
            } 
            element = temp;
        } 
        return Arrays.stream(grid)
    .map(row -> Arrays.stream(row).boxed().collect(Collectors.toList()))
    .collect(Collectors.toList());
    }
}


/*


1   2

3   4


*/ 