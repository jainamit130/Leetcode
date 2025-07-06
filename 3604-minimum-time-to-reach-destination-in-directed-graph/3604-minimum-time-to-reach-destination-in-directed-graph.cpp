class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        vector<vector<vector<int>>> adj(n);
        for(auto e:edges) adj[e[0]].push_back({e[1],e[2],e[3]});
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,0});    
        vector<int> dist(n,INT_MAX);
        dist[0]=0;
        while(!pq.empty()) {
            int time = pq.top()[0];
            int node = pq.top()[1];
            pq.pop();
            for(auto neighNode:adj[node]) {
                int nei = neighNode[0];
                int startTime = neighNode[1];
                int endTime = neighNode[2];
                int newTime = max(startTime,time)+1;
                if(endTime<time || dist[nei]<newTime) continue;
                dist[nei] = newTime;
                pq.push({newTime,nei});
            }
        }
        return dist[n-1]==INT_MAX?-1:dist[n-1];
    }
};