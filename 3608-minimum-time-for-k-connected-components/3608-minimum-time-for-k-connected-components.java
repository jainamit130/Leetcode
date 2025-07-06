class Union {
    private int[] parent;
    private int[] rank;
    private int components;
    public Union(int n) {
        components = n;
        parent = new int[n];
        rank = new int[n];
        for(int i=0;i<n;i++) {
            parent[i]=i;
        }
    }

    public int findParent(int n) {
        while(parent[n]!=n) n = parent[parent[n]];
        return n;
    }

    public boolean merge(int n1,int n2) {
        int p1 = findParent(n1);
        int p2 = findParent(n2);
        if(p1==p2) return true;
        if(rank[p1]>=rank[p2]) {
            parent[p2] = p1;
            rank[p1]++;
        } else {
            parent[p1] = p2;
            rank[p2]++;
        }
        components--;
        return true;
    }

    public int getComponents() {
        return components;
    }
};

class Solution {
    public int minTime(int n, int[][] edges, int k) {
        Arrays.sort(edges,(lhs,rhs)-> lhs[2]-rhs[2]);
        int len = edges.length;
        int start = 0,end = len==0 ? 0 : edges[len-1][2];
        int ans = end;
        while(start<=end) {
            int mid = (start+end)/2;
            if(isValid(k,mid,edges,n)) {
                ans = mid;
                end = mid-1;
            } else start = mid+1;
        }
        return ans;
    }

    public boolean isValid(int k,int time,int[][] edges,int n) {
        Union root = new Union(n);
        int i=edges.length-1;
        while(i>=0) { 
            if(edges[i][2]<=time) break; 
            root.merge(edges[i][0],edges[i][1]); 
            i--; 
        }
        return root.getComponents()>=k;
    }

}