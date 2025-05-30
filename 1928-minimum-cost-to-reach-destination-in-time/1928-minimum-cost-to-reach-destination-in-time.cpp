class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        vector<vector<vector<int>>> adj(n);
        for(auto edge:edges) {
            adj[edge[0]].push_back({edge[1],edge[2]});
            adj[edge[1]].push_back({edge[0],edge[2]});
        }
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({passingFees[0],0,0});
        vector<int> visited(n);
        visited[0]=1;
        while(!pq.empty()) {
            int node = pq.top()[2];
            int currTime = pq.top()[1];
            int currCost = pq.top()[0];
            pq.pop();
            if(node == n-1 && currTime<=maxTime) {
                return currCost;
            }
            for(int i=0;i<adj[node].size();i++) {
                int neigh = adj[node][i][0];
                int time = adj[node][i][1] + currTime;
                if(!visited[neigh] && time<=maxTime) {
                    visited[neigh]=1;
                    pq.push({passingFees[neigh]+currCost,time,neigh});
                } 
            }
        }
        return -1;
    }
};