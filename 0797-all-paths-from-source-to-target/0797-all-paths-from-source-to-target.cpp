class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < edges[i].size(); j++) {
                adj[i].push_back(edges[i][j]);
            }
        }

        vector<int> curr;
        dfs(0, adj, curr);
        return ans;
    }

    void dfs(int source, vector<vector<int>>& adj, vector<int>& curr) {
        if (source == adj.size() - 1) {
            curr.push_back(source);
            ans.push_back(curr);
            curr.pop_back();
            return;
        }

        curr.push_back(source);
        for (int i = 0; i < adj[source].size(); i++) {
            dfs(adj[source][i], adj, curr);
        }
        curr.pop_back();
        return;
    }
};