class Solution {
public:
    int dp[1001][1001];
    int Solve(int src,int dst,int k,unordered_map<int,unordered_map<int,int>> &adj){
        if(src == dst){
            return 0;
        }
        if(k < 0){
            return INT_MAX;
        }
        
        if(dp[src][k] != -1){
            return dp[src][k];
        }
        int ans = INT_MAX;
        for(auto it : adj[src]){
           int t = Solve(it.first,dst,k-1,adj);
            if(t == INT_MAX){
                continue;
            }
           ans = min(ans,it.second + t);
        }
        dp[src][k] = ans;
        return ans;
        
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,unordered_map<int,int>>adj;
        for(auto it : flights){
            adj[it[0]][it[1]]  = it[2];
        }
        memset(dp,-1,sizeof(dp));
        int dp[n+1][k+1];
        
        int t = Solve(src,dst,k,adj);
        if(t == INT_MAX){
            return -1;
        }
        
        return t;
    }
};