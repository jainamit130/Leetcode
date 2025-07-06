class Solution {
public:
    vector<int> safe;
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        safe.resize(n);
        vector<int> visited(n);
        for(int i=0;i<n;i++){              
            dfs(graph,visited,i);
        }
        vector<int> ans;
        for(int i=0;i<safe.size();i++){
            if(safe[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }

    bool dfs(vector<vector<int>>& adj,vector<int>& visited,int node){
        if(safe[node])
            return true;

        if(adj[node].size()==0){
            safe[node]=1;
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
            safe[node]=1;
        }
        return result;
    }
};