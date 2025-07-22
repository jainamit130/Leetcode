class Solution {
    public int minSetSize(int[] arr) {
        Arrays.sort(arr);
        PriorityQueue<Integer> pq = new PriorityQueue<>((lhs,rhs) -> {
            return Integer.compare(rhs,lhs);
        });
        int count = 1;
        int element = arr[0];
        for(int i=1;i<=arr.length;i++) {
            if(i<arr.length && element==arr[i]) {
                count++;
            } else {
                pq.add(count);
                if(i==arr.length) break;
                element = arr[i];
                count=1;
            }
        }

        int ans = 0;
        int size = arr.length/2;
        while(!pq.isEmpty()) {
            if(size-pq.peek()>=0) {
                ans++;
                size-=pq.poll();
            } else {
                break;
            }
        }

        return size>0 ? ans + (pq.isEmpty() ? 0 : 1) : ans;
    }
}


/*


7,1
2,2
5,2
3,4


*/