// #Approach 1
// class Solution {
//     public int nthUglyNumber(int n) {
//         PriorityQueue<Long> pq = new PriorityQueue<Long>();
//         HashSet<Long> visited=new HashSet<Long>();
//         pq.add(1L);
//         int count=0;
//         long top=1l;
//         while(count!=n){
//             top=(long)pq.poll();
//             if(visited.contains(top))
//                 continue;
//             else {
//                 visited.add(top);
//                 count++;
//             }
//             pq.add(top*2);
//             pq.add(top*3);
//             pq.add(top*5);
//         } 
//         return (int)top;
//     }
// }

// #Approach 2
class Solution {
    public int nthUglyNumber(int n) {
        ArrayList<Integer> dp=new ArrayList<Integer>(n);
        dp.add(1);
        int p2=0,p3=0,p5=0;
        for(int i=1;i<n;i++){
            dp.add(Math.min(dp.get(p2)*2,Math.min(dp.get(p3)*3,dp.get(p5)*5)));
            if(dp.get(p2)*2==dp.get(i)) p2++;
            if(dp.get(p3)*3==dp.get(i)) p3++;
            if(dp.get(p5)*5==dp.get(i)) p5++;
        }
        return dp.get(n-1);
    }
}