class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        int mod = 1e9 + 7;

        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(m + 1, 0)));

        for (int maxVal = 0; maxVal <= m; ++maxVal)
            dp[n][k][maxVal] = 1;

        for (int index = n - 1; index >= 0; --index) {
            for (int currPeaks = 0; currPeaks <= k; ++currPeaks) {
                for (int lastMax = 0; lastMax <= m; ++lastMax) {
                    int ans = 0;
                    for (int val = 1; val <= m; ++val) {
                        int newMax = max(lastMax, val);
                        int newPeaks = currPeaks + (val > lastMax ? 1 : 0);
                        if (newPeaks <= k)
                            ans = (ans + dp[index + 1][newPeaks][newMax]) % mod;
                    }
                    dp[index][currPeaks][lastMax] = ans;
                }
            }
        }

        // Initial call: index = 0, peaks = 0, lastMax = 0
        return dp[0][0][0];
    }
};



// class Solution {
// public:
//     vector<vector<vector<int>>> cache;
//     int mod = 1e9+7;
//     int numOfArrays(int n, int m, int k) {
//         if(k==0) return 0;
//         cache.resize(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));
//         return solve(n,m,k,0,0,0);
//     }

//     int solve(int n,int m,int k,int index,int lastMaxElement,int currPeaks) {
//         if(index>=n)  return currPeaks==k;
//         if(currPeaks>k) return 0;
//         if(cache[index][lastMaxElement][currPeaks]!=-1) return cache[index][lastMaxElement][currPeaks];
//         int ans = 0;
//         for(int i=1;i<=m;i++) {
//             ans = (ans + solve(n,m,k,index+1,max(lastMaxElement,i),currPeaks + (lastMaxElement<i)))%mod;
//         }
//         return cache[index][lastMaxElement][currPeaks]=ans;
//     }
// };


/*
n >= 1
m >= 1
k >= 1 && k<=n


conclusions => search costs == no. of strictly increasing peaks

Ex:

x   x   x   

1   2   1-2
1   1   1-2

1   3   1-3
1   1   3


1   1   4
2   2   4
3   2   4


3   4   1-4
2   4   1-4
1   4   1-4


n = 3
m = 4
k = 2

*/