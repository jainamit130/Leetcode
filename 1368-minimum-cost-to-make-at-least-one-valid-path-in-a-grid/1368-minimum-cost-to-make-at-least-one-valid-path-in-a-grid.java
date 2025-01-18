class Solution {
    public int minCost(int[][] grid) {
        int[][] dir = { {0,1}, {0,-1}, {1,0}, {-1,0} }; 
        int m = grid.length;
        int n = grid[0].length;
        int[][][] adj = new int[m][n][4];

        BiPredicate<Integer, Integer> isValid = (row, col) -> row >= 0 && row < m && col >= 0 && col < n;

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                for(int k=1;k<=4;k++) {
                    adj[i][j][k-1]=(grid[i][j]!=k)?1:0;
                }
            }
        }

        PriorityQueue<List<Integer>> minHeap = new PriorityQueue<>(
            Comparator.comparingInt(a -> a.get(0))
        ); 
        int[][][] visited = new int[m][n][4];
        visited[0][0][0]=1;
        visited[0][0][1]=1;
        visited[0][0][2]=1;
        visited[0][0][3]=1;

        minHeap.add(Arrays.asList(0, 0, 0));
        while(!minHeap.isEmpty()) {
            List<Integer> minList = minHeap.poll(); 
            int weight = minList.get(0);
            int row = minList.get(1);
            int col = minList.get(2);
            
            if(row==m-1 && col==n-1) {
                return weight;
            }

            for(int i=0;i<=3;i++) {
                int newRow = row+dir[i][0];
                int newCol = col+dir[i][1];
                if(isValid.test(newRow,newCol) && visited[newRow][newCol][i]==0) {
                    visited[newRow][newCol][i]=1;
                    minHeap.add(Arrays.asList(weight+adj[row][col][i],newRow,newCol));
                }
            }
        }
        return 0;
    }

}

/*

40000

*/