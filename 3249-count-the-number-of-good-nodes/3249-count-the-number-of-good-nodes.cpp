class Solution {
public:
    int ans=0;
    int countGoodNodes(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> visited(n);
        dfs(adj,0,visited);
        return ans;
    }

    int dfs(vector<vector<int>>& adj,int node,vector<int>& visited){
        if(adj[node].size()==0){
            return 0;
        }

        visited[node]=1;
        int flag=0;
        int b=0;
        int t=-1;
        for(int i=0;i<adj[node].size();i++){
            if(visited[adj[node][i]]==1){
                continue;
            }
            int a=dfs(adj,adj[node][i],visited);
            b+=a;
            if(t==-1){
                t=a;
            } else if(t!=a) {
                flag=1;
            }
        }

        if(flag==0){
            ans++;
        }

        return b+1;
    }
};

