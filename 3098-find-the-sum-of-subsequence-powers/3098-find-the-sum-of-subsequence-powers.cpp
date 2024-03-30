class Solution {
public:
    int mod = 1e9+7;
    int dp[52][52][52][51];
    
    int solve(int i, int last, int ind1, int ind2, int k, vector<int>& nums){
        
        if(k == 0)return abs(nums[ind1]-nums[ind2]);
        if(i>=nums.size())return 0;
        
        if(dp[last+1][ind1+1][ind2+1][k]!=-1)return dp[last+1][ind1+1][ind2+1][k];
        
        int temp1 = ind1, temp2 = ind2;
        
        if(last != -1 && (ind1 == -1 || ind2 == -1 || abs(nums[ind1]-nums[ind2])>abs(nums[i]-nums[last]))){
            temp1 = last;
            temp2 = i;
        }
        
        int op1 = solve(i+1,i,temp1,temp2,k-1,nums)%mod;
        int op2 = solve(i+1,last,ind1,ind2,k,nums)%mod;
        
        return dp[last+1][ind1+1][ind2+1][k] = (op1 + op2)%mod;
    }
    int sumOfPowers(vector<int>& nums, int k) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        sort(nums.begin(), nums.end());
        return solve(0,-1,-1,-1,k,nums);
    }
};