class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n  = vals.size();
        vector<vector<int>> adj(n);
        for(auto edge:edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int ans = INT_MIN;
        for(int i=0;i<n;i++) {
            // Consider i as center node 
            int subAns = vals[i];
            priority_queue<int,vector<int>,greater<int>> pq;
            for(auto neigh: adj[i]) {
                if(vals[neigh]>0) pq.push(vals[neigh]);
                if(pq.size()>k) {
                    pq.pop();
                }
            }

            while(!pq.empty()) {
                subAns += pq.top();
                pq.pop();
            }
            ans = max(ans,subAns);
        }
        return ans;
    }
};



/*

1   - 2
    - 3
    - 4
    - 5
    - 6

Edges: ui - vi
values: of size n where n is the number of nodes
values can be negative
empty graph => 0
yes can be disconnected components

create a adjacency list
traverse through all the nodes 
 => a star graph will always be possible 
 => get the max star graph means choose the center and the max k-1 nodes or lesser nodes and that would be the star graph with the node as center node


*/