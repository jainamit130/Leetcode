class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> adj(isConnected.size());
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[i].size();j++){
                if(j==i)
                    continue;
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                }
            }
        }
        int ans=0;
        vector<int> visited(isConnected.size());
        for(int i=0;i<isConnected.size();i++){
            ans+=dfs(adj,i,visited);
        }

        return ans;
    }

    int dfs(vector<vector<int>>& adj,int node,vector<int>& visited){
        if(visited[node]){
            return 0;
        }
        visited[node]=1;
        for(int i=0;i<adj[node].size();i++){
            dfs(adj,adj[node][i],visited);
        }
        return 1;
    }
};