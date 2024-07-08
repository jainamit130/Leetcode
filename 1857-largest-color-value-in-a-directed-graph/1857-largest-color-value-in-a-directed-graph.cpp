class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adj(n);
        vector<int> inDegree(n, 0);

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            inDegree[v]++;
        }

        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(26, 0));
        vector<int> visited(n, 0); 

        for (int i = 0; i < n; ++i) {
            if (visited[i] == 0) {
                if (!dfs(i, adj, colors, dp, visited)) {
                    return -1; 
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int c = 0; c < 26; ++c) {
                ans = max(ans, dp[i][c]);
            }
        }

        return ans;
    }

private:
    bool dfs(int node, vector<vector<int>>& adj, string& colors, vector<vector<int>>& dp, vector<int>& visited) {
        if (visited[node] == 1) {
            return false; 
        }
        if (visited[node] == 2) {
            return true; 
        }

        visited[node] = 1;

        for (int neighbor : adj[node]) {
            if (!dfs(neighbor, adj, colors, dp, visited)) {
                return false; 
            }
            for (int c = 0; c < 26; ++c) {
                dp[node][c] = max(dp[node][c], dp[neighbor][c]);
            }
        }

        dp[node][colors[node] - 'a']++;

        visited[node] = 2;
        return true;
    }
};
