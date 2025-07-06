class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }

        vector<int> visited(n);
        priority_queue<pair<double,int>> pq;
        pq.push({1,start_node});
        while(!pq.empty()){
            int node=pq.top().second;
            double currProb=pq.top().first;
            pq.pop();
            visited[node]=1;
            if(node==end_node){
                return currProb;
            }
            for(int i=0;i<adj[node].size();i++){
                if(visited[adj[node][i].first]){
                    continue;
                }
                pq.push({currProb*adj[node][i].second,adj[node][i].first});
            }
        }
        return 0;
    }
};