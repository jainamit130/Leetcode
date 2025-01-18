class Solution {
    public int minCost(int[][] grid) {
        int[][] dir = { {0,1}, {0,-1}, {1,0}, {-1,0} }; 
        int m = grid.length;
        int n = grid[0].length;

        BiPredicate<Integer, Integer> isValid = (row, col) -> row >= 0 && row < m && col >= 0 && col < n;

        PriorityQueue<List<Integer>> minHeap = new PriorityQueue<>(
            Comparator.comparingInt(a -> a.get(0))
        ); 

        minHeap.add(Arrays.asList(0, 0, 0));

        int[][] distance = new int[m][n];
        for (int[] row : distance) Arrays.fill(row, Integer.MAX_VALUE);
        distance[0][0] = 0;

        while(!minHeap.isEmpty()) {
            List<Integer> minList = minHeap.poll(); 
            int weight = minList.get(0);
            int row = minList.get(1);
            int col = minList.get(2);
            
            if(row==m-1 && col==n-1) {
                return weight;
            }

            if(distance[row][col]<weight) continue;

            for(int i=0;i<4;i++) {
                int newRow = row+dir[i][0];
                int newCol = col+dir[i][1];
                if(isValid.test(newRow,newCol)) {
                    int newWeight = weight + (grid[row][col] != i + 1 ? 1 : 0);
                    if (newWeight < distance[newRow][newCol]) {
                        distance[newRow][newCol] = newWeight;
                        minHeap.add(Arrays.asList(newWeight, newRow, newCol));
                    }
                }
            }
        }
        return -1;
    }

}

/*

40000

*/