// class Solution {
// public:
//     vector<vector<int>> cache;
//     bool canPartition(vector<int>& nums) {
//         int total = accumulate(nums.begin(),nums.end(),0);
//         if(total%2!=0) return false;
//         cache.resize(nums.size()+1,vector<int>((total/2)+1,-1));
//         return solve(nums,0,0,total/2);
//     }

//     bool solve(vector<int>& nums,int index,int sum,int target) {
//         if(sum>target) return false;
//         if(index>=nums.size()) return sum==target;
//         if(cache[index][sum]!=-1) return cache[index][sum];
//         return cache[index][sum]=solve(nums,index+1,sum+nums[index],target) || 
//                 solve(nums,index+1,sum,target);
//     }
// };

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(),nums.end(),0);
        if(total%2!=0) return false;
        int n = nums.size();
        int target = total/2;
        vector<vector<bool>> dp(n+1,vector<bool>(target+1));
        dp[n][target]=true;
        for(int index = n-1; index>=0; index--) {
            for(int sum = target; sum>=0; sum--) {
                dp[index][sum] = dp[index+1][sum];
                if(sum+nums[index]<=target) dp[index][sum] = dp[index][sum] || dp[index+1][sum+nums[index]];
            }
        }
        return dp[0][0];
    }
};


/*

Converting top down to bottom up

States

- Index => going forward
- sum => increasing till total/2

index => n-1 -> 0
sum => total/2 -> 0


*/