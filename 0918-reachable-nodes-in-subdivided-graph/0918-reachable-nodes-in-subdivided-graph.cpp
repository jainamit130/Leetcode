class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        priority_queue<vector<int>> pq;
        unordered_map<int,unordered_map<int,int>> adj;
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]][edges[i][1]]=edges[i][2];
            adj[edges[i][1]][edges[i][0]]=edges[i][2];
        }   
 
        pq.push({maxMoves,0});
        vector<int> visited(n);
        int ans=0;
        while(!pq.empty()){
            int node=pq.top()[1];
            int cost=pq.top()[0];
            pq.pop();
            if(visited[node]){
                continue;
            }
            ans++;
            visited[node]=1;
            for(auto [neighbor,neighborCost]:adj[node]){
                if(!visited[neighbor] && cost>=neighborCost+1){
                    pq.push({cost-neighborCost-1,neighbor});
                }
                int minCost=min(cost,neighborCost);
                adj[node][neighbor]-=minCost;
                adj[neighbor][node] -= minCost;
                ans+=minCost;
            }
        }
        return ans;
    }
};