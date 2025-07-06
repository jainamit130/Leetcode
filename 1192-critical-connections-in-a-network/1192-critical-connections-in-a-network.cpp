class Solution {
public:
    vector<vector<int>> critical;
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for (auto& conn : connections) {
            adj[conn[0]].push_back(conn[1]);
            adj[conn[1]].push_back(conn[0]);
        }

        vector<int> discovery(n, -1); // -1 means unvisited
        vector<int> low(n, -1);       // Low link value for each node
        vector<bool> visited(n, false);

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(adj, i, -1, discovery, low, visited);
            }
        }

        return critical;
    }

    void dfs(vector<vector<int>>& adj, int u, int parent, vector<int>& discovery, vector<int>& low, vector<bool>& visited) {
        static int time = 0;
        visited[u] = true;
        discovery[u] = low[u] = ++time;

        for (int v : adj[u]) {
            if (!visited[v]) {
                dfs(adj, v, u, discovery, low, visited);
                low[u] = min(low[u], low[v]);

                if (low[v] > discovery[u]) {
                    critical.push_back({u, v});
                }
            } else if (v != parent) {
                low[u] = min(low[u], discovery[v]);
            }
        }
    }
};
