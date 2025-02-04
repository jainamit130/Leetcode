class Solution {
public:
    int bfs(vector<vector<int>>& adj, vector<int>& visited, vector<int>& parent, int src) {
        queue<pair<int, int>> q;  
        q.push({src, 0});
        visited[src] = 0;
        int ans = INT_MAX;
        
        while (!q.empty()) {
            int node = q.front().first;
            int distFromSrc = q.front().second;
            q.pop();
            
            for (int neigh : adj[node]) {
                if (visited[neigh]!=INT_MAX && neigh != parent[node]) {
                    ans = min(ans, distFromSrc + 1 + visited[neigh]);  
                    visited[neigh] = min(visited[neigh],distFromSrc + 1);
                }
                if (visited[neigh]==INT_MAX) {
                    visited[neigh] = distFromSrc + 1;
                    parent[neigh] = node;
                    q.push({neigh, distFromSrc + 1});
                }
            }
        }
        
        return ans;
    }

    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int ans = INT_MAX;

        for (int src = 0; src < n; ++src) {
            vector<int> visited(n, INT_MAX);
            vector<int> parent(n, -1);  
            int cycleLength = bfs(adj, visited, parent, src);
            if (cycleLength < ans) {
                ans = cycleLength;
            }
        }

        return ans == INT_MAX ? -1 : ans; 
    }
};
