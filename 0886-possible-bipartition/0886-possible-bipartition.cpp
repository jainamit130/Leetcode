class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        for(int i=0;i<dislikes.size();i++){
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
        }

        vector<int> visited(n+1);
        visited[0]=1;
        for(int i=1;i<n;i++){
            if(visited[i]!=1)
                if(!bfs(adj,visited,i))
                    return false;
        }
        return true;
    }

    bool bfs(vector<vector<int>>& adj,vector<int>& visited,int start){
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int size=q.size();
            while(size){
                int node=q.front();
                q.pop();
                size--;
                if(visited[node]){
                    return false;
                }
                visited[node]=1;
                for(int i=0;i<adj[node].size();i++){
                    q.push(adj[node][i]);
                }
            }
        }
        return true;
    }
};