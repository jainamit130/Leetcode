class Solution {
public:

    int dp[3001][3001];
    int n, m, p;
    int solve(int i, int j, int k, string &source, string &pattern, vector<int>& targetIndices) {
        
        if (j == m)
            return p-k; // Extra indices left in targetIndices
        if (i >= n)
            return -1e6;

        while (i < n && j < m) {
            if (k < p && i == targetIndices[k])
                break;
            if (source[i] == pattern[j]) {
                i++;
                j++;
            } else {
                i++;
            }
        }

        if (k == p) {
            if (j == m)
                return 0;
            else return -1e6;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        // skip 
        int val1 = 1 + solve(i+1, j, k+1, source, pattern, targetIndices);

        // not skip
        int val2 = solve(i, j, k+1, source, pattern, targetIndices);

        return dp[i][j] = max(val1, val2);

    }

    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        
        n = source.size();
        m = pattern.size();
        p = targetIndices.size();

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, 0, source, pattern, targetIndices);

    }
};