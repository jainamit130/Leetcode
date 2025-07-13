class Solution {
public:
    vector<vector<vector<int>>> cache;
    int maxLen(int n, vector<vector<int>>& edges, string label) {
        vector<vector<int>> adj(n);
        for(auto edge:edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int ans = 1;
        cache.resize(n+1,vector<vector<int>>(n+1,vector<int>(1<<14,-1)));
        for(int i=0;i<n;i++) {
            ans = max(ans,1+solve(adj,0|(1<<i),i,i,label));
            for(int j=0;j<adj[i].size();j++) {
                if(label[adj[i][j]]==label[i]) {
                    ans = max(ans,2+solve(adj,0|(1<<adj[i][j])|(1<<i),adj[i][j],i,label));
                }
            }
        }
        return ans;
    }

    int solve(vector<vector<int>>& adj,int mask,int node1,int node2,string& label) {
        if(cache[node1][node2][mask]!=-1) return cache[node1][node2][mask];
        int ans = 0;
        for(int i=0;i<adj[node1].size();i++) {
            if((mask>>adj[node1][i])&1) continue;
            for(int j=0;j<adj[node2].size();j++) {
                if(((mask>>adj[node2][j])&1) || adj[node2][j]==adj[node1][i]) continue;
                if(label[adj[node2][j]]==label[adj[node1][i]]) ans = 2 + solve(adj,mask | (1<<adj[node2][j]) | (1<<adj[node1][i]),adj[node1][i],adj[node2][j],label);
            }
        }
        return cache[node1][node2][mask]=ans;
    }
};