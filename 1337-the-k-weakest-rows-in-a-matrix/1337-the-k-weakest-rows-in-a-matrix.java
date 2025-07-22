class Solution {
    public int[] kWeakestRows(int[][] mat, int k) {
        PriorityQueue<List<Integer>> pq = new PriorityQueue<>((lhs,rhs)-> {
            if(lhs.get(0)==rhs.get(0)) return Integer.compare(rhs.get(1),lhs.get(1));
            return Integer.compare(rhs.get(0),lhs.get(0));
        });

        for(int i=0;i<mat.length;i++) {
            int count = 0;
            for(int j=0;j<mat[0].length && mat[i][j]==1;j++) {
                count++;
            }
            pq.add(List.of(count,i));
            if(pq.size()>k) pq.poll();
        }
        
        int[] ans = new int[pq.size()];
        int index = ans.length-1;
        while(!pq.isEmpty()) ans[index--] = pq.poll().get(1);
        return ans;
    }
}