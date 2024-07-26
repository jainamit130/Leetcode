class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> distances(n,vector<int>(n,INT_MAX));
        vector<vector<vector<int>>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        for(int i=0;i<n;i++){
            pq.push({0,i,i});
        }
        while(!pq.empty()){
            int node=pq.top()[1];
            int src=pq.top()[2];
            int distance=pq.top()[0];
            pq.pop();
            if(src!=node){
                distances[src][node]=min(distances[src][node],distance);
                distances[node][src]=min(distances[node][src],distance);
            }
            
            for(int i=0;i<adj[node].size();i++){
                if(distances[src][adj[node][i][0]]==INT_MAX && distance+adj[node][i][1]<=distanceThreshold){
                    pq.push({distance+adj[node][i][1],adj[node][i][0],src});
                }
            }
        }

        int cities=INT_MAX;
        int ans=-1;
        for(int i=0;i<distances.size();i++){
            int currCities=0;
            for(int j=0;j<distances[i].size();j++){
                if(distances[i][j]!=INT_MAX){
                    currCities++;
                }
            }
            if(cities>=currCities){
                cities=currCities;
                ans=i;
            }
        }
        return ans;
    }
};