class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n);
        vector<int> dp(n);
        vector<int> indeg(n);
        for (auto edge : relations) {
            adj[edge[0] - 1].push_back(edge[1] - 1);
            indeg[edge[1] - 1]++;
        }
        int ans = 0;
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) {
                q.push(i);
                dp[i] = time[i];
            }
        }

        while (!q.empty()) {
            int currNode = q.front();
            q.pop();
            for (int i = 0; i < adj[currNode].size(); i++) {
                indeg[adj[currNode][i]]--;
                dp[adj[currNode][i]] = max(dp[adj[currNode][i]],time[adj[currNode][i]] + dp[currNode]);
                ans = max(dp[adj[currNode][i]], ans);
                if (indeg[adj[currNode][i]] == 0) q.push(adj[currNode][i]);
            }
        }
        for (int i = 0; i < n; i++) ans = max(ans, dp[i]);
        return ans;
    }
};

/*

1   2   3   4   5



*/