class Solution {
public:
    int n;
    vector<vector<vector<long long>>> dp;
    long long maximumProfit(vector<int>& prices, int k) {
        n = prices.size();
        dp.resize(prices.size() + 1, vector<vector<long long>> (k + 1, vector<long long> (3, -1)));

        return solve(prices,k,0,0);
    }

    long long solve(vector<int>& prices,int k,int index,int type) {
        if(index>=n) return type==0?0:-1e14;
        if(dp[index][k][type] != -1) return dp[index][k][type];

        long long ans = LLONG_MIN;
        ans = max(ans,solve(prices,k,index+1,type));
        if(type!=0 && k>0) {
            if(type == 1) {
                ans = max(ans,prices[index] + solve(prices,k-1,index+1,0));
            } else if(type==2) {
                ans = max(ans,-prices[index] + solve(prices,k-1,index+1,0));
            }
        } else {
            ans = max(ans,-prices[index] + solve(prices,k,index+1,1));
            ans = max(ans,prices[index] + solve(prices,k,index+1,2));
        }
        return dp[index][k][type]=ans;
    }
};