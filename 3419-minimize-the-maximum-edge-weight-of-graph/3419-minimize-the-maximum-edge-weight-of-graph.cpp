class Solution {
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        vector<vector<vector<int>>> adj(n);
        for(int i=0;i<edges.size();i++) {
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }

        int start = 1;
        int end = 1e6+1;
        int ans = end;
        while(start<=end) {
            int mid = (start+end)/2;
            vector<int> visited(n);
            visited[0]=1;
            if(dfs(adj,visited,0,mid)==n) {
                ans = mid;
                end=mid-1;
            } else {
                start = mid+1;
            }
        }
        return (ans==(1e6+1))?-1:ans;
    }

    int dfs(vector<vector<vector<int>>>& adj,vector<int>& visited,int node,int maxWt) {
        int totalNodes = 1;
        for(int i=0;i<adj[node].size();i++) {
            int nextNode = adj[node][i][0];
            if(maxWt>=adj[node][i][1] && visited[nextNode]==0) {
                visited[nextNode]=1;
                totalNodes += dfs(adj,visited,nextNode,maxWt);
            }
        }
        return totalNodes;
    }
};


/*

1 - 1e6








*/