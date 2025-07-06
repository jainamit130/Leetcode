class Union {
    private int[] parent;
    private int[] rank;
    public Map<Integer,TreeSet<Integer>> online;
    public Union(int n) {
        parent = new int[n];
        rank = new int[n];
        online = new HashMap<>();
        for(int i=0;i<n;i++) { 
            TreeSet<Integer> st = new TreeSet<>();
            st.add(i);
            online.put(i,st);
            parent[i]=i;
        }
    }

    public int findParent(int n) {
        while(n!=parent[n]) n = parent[parent[n]];
        return n;
    }

    public boolean merge(int n1,int n2) {
        int p1 = findParent(n1);
        int p2 = findParent(n2);
        if(p1==p2) return true;
        if(rank[p1]>=rank[p2]) {
            parent[p2] =  p1;
            rank[p1]++;
            TreeSet<Integer> st = online.get(p1);
            st.addAll(online.get(p2));
        } else {
            parent[p1] = p2;
            rank[p2]++;
            TreeSet<Integer> st = online.get(p2);
            st.addAll(online.get(p1));
        }
        return true;
    }

    public void turnOffline(int n) {
        int p = findParent(n);
        online.get(p).remove(n);
        return;
    }

    public int performMaintanance(int n) {
        int p = findParent(n);
        TreeSet<Integer> st = online.get(p);
        if(st.size()==0) return -1;
        int ans = st.contains(n)?n:st.first();
        return ans; 
    }
};

class Solution {
    public int[] processQueries(int c, int[][] connections, int[][] queries) {
        Union root = new Union(c+1);
        for(int i=0;i<connections.length;i++) root.merge(connections[i][0],connections[i][1]);
        List<Integer> ans = new ArrayList<>();
        for(int i=0;i<queries.length;i++) {
            int node = queries[i][1];
            if(queries[i][0]==1) {
                ans.add(root.performMaintanance(node));  
            } else {
                root.turnOffline(node);
            }
        }
        return ans.stream().mapToInt(Integer::intValue).toArray();
    }
}