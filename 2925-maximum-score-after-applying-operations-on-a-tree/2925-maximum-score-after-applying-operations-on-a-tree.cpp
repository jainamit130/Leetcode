class Solution {
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges,vector<int>& values) {
        int n = values.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        long long total=0;
        for(int i=0;i<n;i++){
            total+=values[i];
        }
        return total-minValRem(adj, 0, -1,values);
    }

    long long minValRem(vector<vector<int>>& adj, int node, int parent, vector<int>& values) {
        long long val=values[node];
        long long sumChild=0;
        for(int i=0;i<adj[node].size();i++){
            if(parent!=adj[node][i])
                sumChild+=minValRem(adj, adj[node][i],node,values);
        }
        if(sumChild==0) return val;
        return min(sumChild,val);
    }   
};