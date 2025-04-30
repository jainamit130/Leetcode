class Solution {
public:
    int numWays(int steps, int arrLen) {
        int mod = 1e9+7;
        int maxPos = min(arrLen,steps/2+1);
        vector<vector<int>> dp(steps+1,vector<int>(maxPos+1,0));
        dp[0][0]=1;
        for(int i=1;i<=steps;i++) {
            for(int j=0;j<maxPos;j++) {
                dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
            }

            for(int j=1;j<maxPos;j++) {
                dp[i][j]=(dp[i][j]+dp[i-1][j-1])%mod;
            }

            for(int j=0;j<maxPos-1;j++) {
                dp[i][j]=(dp[i][j]+dp[i-1][j+1])%mod;
            }
        }

        return dp[steps][0];
    }
};

// class Solution {
// public:
//     int mod = 1e9+7;
//     vector<vector<int>> cache;
//     int numWays(int steps, int arrLen) {
//         cache.resize(steps+1,vector<int>(min(arrLen,steps/2+1)+1,-1));
//         return solve(steps,0,min(arrLen,steps/2+1));
//     }

//     int solve(int steps,int pos,int arrLen) {
//         if(pos>=arrLen || pos<0) return 0;
//         if(steps==0) return pos==0;
//         if(cache[steps][pos]!=-1) return cache[steps][pos];
//         int ans = 0;
//         ans = (ans + solve(steps-1,pos+1,arrLen))%mod;
//         ans = (ans + solve(steps-1,pos,arrLen))%mod;
//         ans = (ans + solve(steps-1,pos-1,arrLen))%mod;
//         return cache[steps][pos]=ans;
//     }
// };