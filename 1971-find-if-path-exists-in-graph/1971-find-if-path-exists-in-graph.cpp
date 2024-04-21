class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        unordered_set<int> visited;
        return dfs(adj,source,destination,visited);
    }
    bool dfs(vector<vector<int>>& adj,int source,int destination,unordered_set<int>& visited){
        if(source==destination)
            return true;

        if(visited.find(source)!=visited.end())
            return false;

        bool flag=false;
        for(auto newSource:adj[source]){
            if(visited.find(newSource)!=visited.end())
                continue;
            visited.insert(source);
            flag=flag||dfs(adj,newSource,destination,visited);
        }
        return flag;
    }
};