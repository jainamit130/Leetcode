class Solution {
public:
    using pii=pair<double,int>;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pii>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({succProb[i],edges[i][1]});
            adj[edges[i][1]].push_back({succProb[i],edges[i][0]});
        }
        priority_queue<pii> pq;
        pq.push({1,start_node});
        vector<double> probabilities(n,1);
        vector<int> visited(n);
        while(!pq.empty()){
            int node=pq.top().second;
            double prob=pq.top().first;
            pq.pop();
            if(visited[node]){
                continue;
            }
            visited[node]=1;
            probabilities[node]*=prob;
            for(int i=0;i<adj[node].size();i++){
                pq.push({adj[node][i].first*prob,adj[node][i].second});
            }
        }
        if(probabilities[end_node]==1){
            return 0;
        }
        return probabilities[end_node];
    }
};