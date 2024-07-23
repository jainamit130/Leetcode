class Solution {
public:
    set<int> safe;
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
        }

        vector<int> visited(n);
        for(int i=0;i<n;i++){              
            dfs(adj,visited,i);
        }
        vector<int> ans(safe.begin(),safe.end());
        return ans;
    }

    bool dfs(vector<vector<int>>& adj,vector<int>& visited,int node){
        if(safe.find(node)!=safe.end())
            return true;

        if(adj[node].size()==0){
            safe.insert(node);
            return true;
        }
        
        if(visited[node]){
            return false;
        }

        visited[node]=1;
        bool result=true;
        for(int i=0;i<adj[node].size();i++){
            result&=dfs(adj,visited,adj[node][i]);
        }
        if(result){
            safe.insert(node);
        }
        return result;
    }
};