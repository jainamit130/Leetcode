class Solution {
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges,vector<int>& values) {
        int n = values.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        long long total=0;
        for(int i=0;i<n;i++){
            total+=values[i];
        }
        return total-minValRem(adj, 0, values);
    }

    long long minValRem(vector<vector<int>>& adj, int node, vector<int>& values) {
        if(adj[node].size()==0){
            return values[node];
        }

        long long val=values[node];
        long long sumChild=0;
        for(int i=0;i<adj[node].size();i++){
            sumChild+=minValRem(adj, adj[node][i],values);
        }
        return min(sumChild,val);
    }   
};