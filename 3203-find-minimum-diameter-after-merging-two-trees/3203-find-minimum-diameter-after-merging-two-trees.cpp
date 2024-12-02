class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size()+1;
        int m = edges2.size()+1;
        vector<vector<int>> adj1 = constructAdj(edges1);
        vector<vector<int>> adj2 = constructAdj(edges2);

        int maxD1=0,maxD2=0;
        vector<int> visited1(n),visited2(m);
        getMaxDiameter(adj1,0,visited1,maxD1);
        getMaxDiameter(adj2,0,visited2,maxD2);

        return max({maxD1,maxD2,(maxD1+1)/2+(maxD2+1)/2 + 1});
    }

    int getMaxDiameter(vector<vector<int>>& adj,int node,vector<int>& visited,int& maxDiameter) {
        visited[node]=1;
        priority_queue<int,vector<int>,greater<int>> pq;
        int maxDepth = 0;
        for(auto neigh:adj[node]) {
            if(visited[neigh]!=1){
                int childDepth = getMaxDiameter(adj,neigh,visited,maxDiameter);
                maxDepth = max(childDepth,maxDepth);
                pq.push(childDepth);
                if(pq.size()>2) pq.pop();
            }
        }
        int subDiameter = 0;
        while(!pq.empty()) {
            subDiameter += pq.top();
            pq.pop();
        }
        maxDiameter = max(maxDiameter,subDiameter);
        return maxDepth+1;
    }

    vector<vector<int>> constructAdj(vector<vector<int>>& edges) {
        vector<vector<int>> adj(edges.size()+1);
        for(auto edge:edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return adj;
    }
};


/*

Max dist to reach a node (n) = 1 + min(Max dist to reach a node (neigh))




*/