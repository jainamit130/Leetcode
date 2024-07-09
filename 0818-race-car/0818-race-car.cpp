class Solution {
public:
    int racecar(int target) {
        vector<int> dp(target+1,-1);
        return solve(target,dp);
    }

    int solve(int target,vector<int>& dp){
        if(dp[target]!=-1){
            return dp[target];
        }

        int n=floor(log2(target))+1;
        if((1<<n)-1==target){
            return n;
        }

        dp[n]=n+1+solve((1<<n)-1-target,dp);
        for(int i=0;i<n-1;i++){
            dp[n]=min(dp[n],n+i+1+solve(target-(1<<(n-1))+(1<<i),dp));
        }
        return dp[n];
    }
};


/*





*/