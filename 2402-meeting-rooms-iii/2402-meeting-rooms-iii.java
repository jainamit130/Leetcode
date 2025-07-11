class Solution {
    public int mostBooked(int n, int[][] meetings) {
        Arrays.sort(meetings,(int[] l, int[] r) -> {
            return l[0]-r[0];
        });

        PriorityQueue<Integer> freeRooms = new PriorityQueue<>();

        PriorityQueue<List<Integer>> pq = new PriorityQueue<>((List<Integer> lhs,List<Integer> rhs) -> {
            if(lhs.get(0)==rhs.get(0)) return lhs.get(1)-rhs.get(1);
            return lhs.get(0)-rhs.get(0);
        });

        int currTime = 0;
        Map<Integer,Integer> mp = new HashMap();
        for(int i=0;i<n;i++) freeRooms.add(i);
        
        for(int i=0;i<meetings.length;i++) {
            currTime = meetings[i][0];
            int duration = meetings[i][1] - meetings[i][0];;
            // transfer all rooms that are free
            while(!pq.isEmpty() && pq.peek().get(0)<=currTime) freeRooms.add(pq.poll().get(1));    
            if(!freeRooms.isEmpty()) {
                mp.put(freeRooms.peek(),mp.getOrDefault(freeRooms.peek(),0)+1);
                pq.add(new ArrayList<>(Arrays.asList(currTime + duration,freeRooms.poll())));
            } else if(!pq.isEmpty()) {
                int currEndTime = pq.peek().get(0);
                int room = pq.peek().get(1);
                pq.poll();
                mp.put(room,mp.getOrDefault(room,0)+1);
                pq.add(new ArrayList(Arrays.asList(currEndTime+duration,room)));
            }
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