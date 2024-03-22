class Solution {
public:
    double ans=0.0;
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<unordered_set<int>> adj(n+1);
        for(auto e:edges){
            adj[e[0]].insert(e[1]);
            adj[e[1]].insert(e[0]);
        }
        unordered_set<int> visited;
        dfs(adj,1,t,visited,target,1.0);
        return ans;
    }

    void dfs(vector<unordered_set<int>>& adj,int currentVertex,int time,unordered_set<int>& visited,int target,double prob) {
        if(visited.find(currentVertex)!=visited.end()){
            return;
        }

        if(time<0){
            return;
        }

        if(currentVertex==target && (adj[currentVertex].size()==0 || time==0)){ 
            ans=prob;
            return;
        }
        visited.insert(currentVertex);
        for(auto a:adj[currentVertex]){
            if(visited.find(a)!=visited.end()){
                continue;
            }
            adj[a].erase(currentVertex);
            dfs(adj,a,time-1,visited,target,prob*(1.0/adj[currentVertex].size()));
            adj[a].insert(currentVertex);
        }
        return;
    }
};