class Solution {
public:
    int mod=1e9+7;
    int countOfPairs(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(2000,0));
        vector<int> base(2000,1);
        dp[n]=base;
        for(int index=n-1;index>=0;index--){
            for(int arr1B=0;arr1B<=nums[index];arr1B++){
                int arr2B=(index>0)?nums[index-1]-arr1B:2000;
                int ans=0;
                for(int i=arr1B;i<=nums[index];i++){
                    if(nums[index]-i<=arr2B){
                        ans=ans%mod+dp[index+1][i]%mod;
                    }
                }
                dp[index][arr1B]=ans;
            }
        }

        return dp[0][0]; 
    }
};