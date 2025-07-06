class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer,Integer> map = new HashMap<>();
        for(int n:nums) {
            map.put(n,map.getOrDefault(n,0)+1);
        }

        PriorityQueue<List<Integer>> pq = new PriorityQueue<>((List<Integer> i1,List<Integer> i2) -> i1.get(0)-i2.get(0));
        for(Map.Entry<Integer,Integer> entry:map.entrySet()) {
            pq.add(Arrays.asList(entry.getValue(),entry.getKey()));
            if(pq.size()>k) pq.poll();
        }

        int[] ans = new int[k];
        int index = 0;
        while(!pq.isEmpty()) {
            ans[index]=pq.poll().get(1);
            index++;
        }
        return ans;
    }
}