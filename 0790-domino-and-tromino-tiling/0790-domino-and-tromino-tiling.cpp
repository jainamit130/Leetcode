class Solution {
    public:
        const long mod = 1e9 + 7;
        long dominoes(int i, int n, bool possible) {
            if (i == n) return !possible;
            if (i > n) return 0;
            if (possible)
                return (dominoes(i + 1, n, false) + 
                        dominoes(i + 1, n, true)) % mod;
            return (dominoes(i + 1, n, false) + 
                    dominoes(i + 2, n, false) + 
                    2L * dominoes(i + 2, n, true)) % mod;
            }

        int numTilings(int n) {
            return dominoes(0, n, false);
        }
    };