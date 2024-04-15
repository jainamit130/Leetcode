class Solution {
    public int nthUglyNumber(int n) {
        PriorityQueue<Long> pq = new PriorityQueue<Long>();
        HashSet<Long> visited=new HashSet<Long>();
        pq.add(1L);
        int count=0;
        long top=1l;
        while(count!=n){
            top=(long)pq.poll();
            if(visited.contains(top))
                continue;
            else {
                visited.add(top);
                count++;
            }
            pq.add(top*2);
            pq.add(top*3);
            pq.add(top*5);
        } 
        return (int)top;
    }
}