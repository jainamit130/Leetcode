class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<vector<int>>> adj(n+1);
        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }

        vector<int> distances(n+1,INT_MAX);
        vector<int> visited(n+1);
        int visitedCount=0;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,k});
        while(!pq.empty()){
            int node=pq.top()[1];
            int time=pq.top()[0];
            pq.pop();
            visited[node]=1;
            visitedCount++;
            distances[node]=min(distances[node],time);
            if(visitedCount==n){
                return distances[node];
            }
            for(int i=0;i<adj[node].size();i++){
                if(!visited[adj[node][i][0]]){
                    pq.push({adj[node][i][1]+time,adj[node][i][0]});
                }
            }
        }
        return -1;
    }
};



/* 

Confirm No Empty Nodes
Cycle present?
Parallel Edges?
1 to n+1 or 0 to n-1



*/