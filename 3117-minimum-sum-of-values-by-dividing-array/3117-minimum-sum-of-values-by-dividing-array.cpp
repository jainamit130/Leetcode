class Solution {
public:
    int initialAnd = (1<<17)-1;
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        vector<vector<unordered_map<int,int>>> dp(nums.size()+1,vector<unordered_map<int,int>>(andValues.size()+1));
        int result=solve(nums,andValues,0,0,initialAnd,dp);
        return result==1e9?-1:result;
    }

    int solve(vector<int>& nums, vector<int>& andValues,int i,int j,int currAnd,vector<vector<unordered_map<int,int>>>& dp){
        if(i>=nums.size()){
            if(j>=andValues.size())
                return 0;
            else
                return 1e9;
        } else if(j>=andValues.size())
            return 1e9;

        if(dp[i][j].find(currAnd)!=dp[i][j].end())
            return dp[i][j][currAnd];
        int including=1e9;
        if((currAnd & nums[i]) == andValues[j])
            including=nums[i]+solve(nums,andValues,i+1,j+1,initialAnd,dp);
        int excluding=solve(nums,andValues,i+1,j,currAnd&nums[i],dp);
        return dp[i][j][currAnd]=min(including,excluding);
    }
};