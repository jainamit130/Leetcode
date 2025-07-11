class Solution {
    public int mostBooked(int n, int[][] meetings) {
        Arrays.sort(meetings,(int[] l, int[] r) -> {
            return l[0]-r[0];
        });
        PriorityQueue<List<Integer>> pq = new PriorityQueue<>((List<Integer> lhs,List<Integer> rhs) -> {
            if(lhs.get(0)==rhs.get(0)) return lhs.get(1)-rhs.get(1);
            return lhs.get(0)-rhs.get(0);
        });
        int currTime = 0;
        Map<Integer,Integer> mp = new HashMap();
        for(int i=0;i<n;i++) {
            pq.add(Arrays.asList(0,i));
        }

        for(int i=0;i<meetings.length;i++) {
            List<List<Integer>> freeRooms = new ArrayList<>();
            currTime = Math.max(pq.peek().get(0),meetings[i][0]);
            while(!pq.isEmpty() && pq.peek().get(0)<=currTime) {
                freeRooms.add(pq.poll());
            }
            for(int j=0;j<freeRooms.size();j++) {
                freeRooms.get(j).set(0,0);
            }
            pq.addAll(freeRooms);
            int currEndTime = pq.peek().get(0);
            int room = pq.peek().get(1);
            mp.put(room,mp.getOrDefault(room,0)+1);
            pq.poll();
            int duration = meetings[i][1] - meetings[i][0];
            pq.add(new ArrayList(Arrays.asList(currTime+duration,room)));
        }
        int count = 0;
        int ans = n-1;
        for(int i=n-1;i>=0;i--) {
            if(count<=mp.getOrDefault(i,0)) {
                count = mp.getOrDefault(i,0);
                ans = i;
            }
        }
        return ans;
    }
}

/*
Map
room0 -> 1
room1 -> 1
room2 -> 1
room3 -> 0

currTime = 17

pq1
room3 -> 0,3
room2 -> 10,2
room1 -> 12,1
room0 -> 12,0



17  19
18  19


*/ 