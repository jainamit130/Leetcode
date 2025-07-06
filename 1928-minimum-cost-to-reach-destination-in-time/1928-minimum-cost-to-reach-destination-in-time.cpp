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
        vector<vector<int>> visited(n,{INT_MAX,INT_MAX});
        visited[0]={passingFees[0],0};
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
                if((visited[neigh][0]>currCost+passingFees[neigh] || visited[neigh][1]>time) && time<=maxTime) {
                    visited[neigh]={currCost+passingFees[neigh],time};
                    pq.push({passingFees[neigh]+currCost,time,neigh});
                } 
            }
        }
        return -1;
    }
};