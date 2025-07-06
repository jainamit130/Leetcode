class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<vector<int>>> adj(n);
        for(int i=0;i<redEdges.size();i++){
            adj[redEdges[i][0]].push_back({redEdges[i][1],0});
        }

        for(int i=0;i<blueEdges.size();i++){
            adj[blueEdges[i][0]].push_back({blueEdges[i][1],1});
        }

        vector<int> ans(n,INT_MAX);
        vector<vector<vector<int>>> visited(n,vector<vector<int>>(n,vector<int>(2,-1)));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,1,0,-1});
        pq.push({0,0,0,-1});
        while(!pq.empty()){
            int node=pq.top()[2];
            int color=pq.top()[1];
            int cost=pq.top()[0];
            int source=pq.top()[3];
            pq.pop();
            ans[node]=min(ans[node],cost);
            if(source!=-1)
                visited[source][node][color]=1;
            for(int i=0;i<adj[node].size();i++){
                int neigh=adj[node][i][0];
                int neighColor=adj[node][i][1];
                if(visited[node][neigh][neighColor]!=1 && neighColor!=color){
                    pq.push({cost+1,neighColor,neigh,node});
                }
            }
        }
        for(auto& a:ans){
            if(a==INT_MAX){
                a=-1;
            }
        }
        return ans;
    }
};























