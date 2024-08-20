class Solution {
public:
    int n;
    vector<vector<vector<int>>> dp;
    
    int solve(vector<int>& piles, int index, int M, bool turn) {
        if (index >= n) {
            return 0;
        }
        
        if (dp[index][M][turn] != -1) {
            return dp[index][M][turn];
        }
        
        int a = (turn == 0) ? 0 : INT_MAX;
        int total = 0;
        int xN = min(2 * M, n - index);
        
        for (int i = 1; i <= xN; i++) {
            total += piles[index + i - 1];
            int nextM = max(M, i);
            if (turn == 0) {
                a = max(a, total + solve(piles, index + i, nextM, !turn));
            } else {
                a = min(a, solve(piles, index + i, nextM, !turn));
            }
        }
        
        return dp[index][M][turn] = a;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        dp.assign(n, vector<vector<int>>(n + 1, vector<int>(2, -1)));
        return solve(piles, 0, 1, 0);
    }
};
