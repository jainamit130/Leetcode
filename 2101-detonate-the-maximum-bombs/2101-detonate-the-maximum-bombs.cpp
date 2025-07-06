class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(i!=j){
                double distance = sqrt(abs(pow(bombs[i][0] - bombs[j][0], 2)) + pow(abs(bombs[i][1] - bombs[j][1]), 2));
                    if(distance<=(double)bombs[i][2]){
                        adj[i].push_back(j);
                    }
                    if(distance<=(double)bombs[j][2]){
                        adj[j].push_back(i);
                    }
                }
            }
        }

        int ans=1;
        for(int i=0;i<n;i++){
            vector<int> visited(n,-1);
            int a=countDetonation(adj,i,visited);
            ans=max(ans,a);
        }
        return ans;
    }

    int countDetonation(vector<vector<int>>& adj,int node,vector<int>& visited){
        if(visited[node]==1){
            return 0;
        }
        int count=1;
        visited[node]=1;
        for(int i=0;i<adj[node].size();i++){
            count+=countDetonation(adj,adj[node][i],visited);
        }
        return count;
    }
};