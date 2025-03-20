class Solution {
public:
    vector<int> ans;
    void helper(int i,vector<int>& nums,vector<int>& vec,vector<int>& dp){
        if(i==nums.size()){
            if(vec.size()>ans.size())
                ans=vec;
            return;
        }
        if(vec.size()==0){
            vec.push_back(nums[i]);
            helper(i+1,nums,vec,dp);
            vec.pop_back();
        }
        else if((int)vec.size()>dp[i] && nums[i]%vec.back()==0){
            dp[i]=vec.size();
            vec.push_back(nums[i]);
            helper(i+1,nums,vec,dp);
            vec.pop_back();
        }
        helper(i+1,nums,vec,dp);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> vec;
        vector<int> dp(nums.size()+1,-1);
        sort(nums.begin(),nums.end());
        helper(0,nums,vec,dp);
        return ans;
    }
};