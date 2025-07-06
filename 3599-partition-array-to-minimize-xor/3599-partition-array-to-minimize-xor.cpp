class Solution {
public:
    vector<vector<int>> dp; int n;
    int minXor(vector<int>& nums, int k) {
        n = nums.size();
        dp.resize(n+1,vector<int>(k+1,-1));
        return solve(nums,0,0,k);
    }

    int solve(vector<int>& nums,int index,int currXor,int k) {
        if(index>=n) return k==0 ? 0:INT_MIN;
        if(k==0) return INT_MIN;
        if(dp[index][k]!=-1) return dp[index][k];
        int ans = INT_MAX;
        for(int i=index;i<n;i++) {
            currXor ^= nums[i];
            int subAns = solve(nums,i+1,0,k-1);
            if(subAns>=0) ans = min(ans,max(currXor,subAns));
        }
        return dp[index][k] = ans;
    }
};