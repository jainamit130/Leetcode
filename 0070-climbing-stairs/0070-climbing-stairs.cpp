// class Solution {
// public:
//     int climbStairs(int n) {
//         vector<int> cache(n+1);
//         return climb(n,cache);
//     }
//     int climb(int n,vector<int>& cache) {
//         if(n<=1)
//             return 1;
//         if(cache[n]!=0)
//             return cache[n];
//         return cache[n]=climb(n-1,cache)+climb(n-2,cache);
//     }
// };

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};