class Solution {
public:
    vector<int> ans;
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < richer.size(); i++) {
            adj[richer[i][1]].push_back(richer[i][0]);
        }
        ans.resize(n,-1);
        for (int i = 0; i < n; i++) {
            if(ans[i]==-1) {
                vector<int> visited(n);
                dfs(adj, i, visited, quiet);
            }
        }
        return ans;
    }

    pair<int,int> dfs(vector<vector<int>>& adj, int node,vector<int>& visited, vector<int>& quiet) {
        visited[node] = 1;
        int currVal=quiet[node];
        int index=node;
        for (int i = 0; i < adj[node].size(); i++) {
            if(visited[adj[node][i]]!=1){
                auto returnedPair=dfs(adj, adj[node][i], visited, quiet);
                if(currVal>returnedPair.second){
                    currVal=returnedPair.second;
                    index=returnedPair.first;
                }
            }
        }
        if(ans[node]==-1)
            ans[node]=index;
        return {index,currVal};
    }
};
