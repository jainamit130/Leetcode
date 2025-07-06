class Solution {
    public int maxRemoval(int[] nums, int[][] queries) {
        Arrays.sort(queries, new Comparator<int[]>() {
            @Override
            public int compare(int[] a, int[] b) {
                if(a[0]==b[0]) return Integer.compare(b[1],a[1]);
                return Integer.compare(a[0], b[0]); 
            }
        });
        PriorityQueue<Integer> choosenHeap = new PriorityQueue(); 
        PriorityQueue<Integer> candidateHeap = new PriorityQueue(new Comparator<Integer>() {
            @Override
            public int compare(Integer lhs, Integer rhs) {
                return rhs-lhs;
            }
        });
        int choosen = 0;
        int j = 0;
        for(int i=0;i<nums.length;i++) {
            // remove all invalid elements from the candidatesHeap
            while(!candidateHeap.isEmpty() && candidateHeap.peek()<i) candidateHeap.poll();

            // add all valid queries
            while(j<queries.length && queries[j][0]<=i && i<=queries[j][1]) {
                candidateHeap.add(queries[j][1]);
                j++;
            }
            // remove all invalid elements from the choosen heap
            while(!choosenHeap.isEmpty() && choosenHeap.peek()<i) choosenHeap.poll();  

            int reducedVal = nums[i]-choosenHeap.size();
            
            while(reducedVal>0 && !candidateHeap.isEmpty() && candidateHeap.peek()>=i) {
                choosenHeap.add(candidateHeap.poll());
                reducedVal -= 1;
                choosen++;
            }

            if(reducedVal>0) return -1; 
        }

        return queries.length-choosen;
    }
}


/*

Steps

1. Sort the intervals and initialize the candidates max heap and choosen min heap
2. iterate the nums array
3. for each nums[i]. Add the valid candidate's ending index into the maxHeap before adding remove the indexes which are no longer valid
4. validate the choosen heap and then check if the size of chosen heap is >= the value nums[i] if not then try to see if it happens by popping the candidates array into the choosen if not possible then return -1
6. keep count of choosen candidates 
5. repeat for all elements
7. return total queries - choosen count


*/