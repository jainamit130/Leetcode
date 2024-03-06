class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        if(nums.size()==0 || nums.size()==1 ||nums.size()==2)
            return true;
        int sum=0;
        vector<vector<int>> memoization(nums.size()+1,vector<int>(nums.size()+1,-1));
        for(auto n:nums)
            sum+=n;
        return dp(nums,0,nums.size()-1,sum,m,memoization);
    }

    bool dp(vector<int>& nums,int i,int j,int sum,int m,vector<vector<int>>& memoization){
        if(i>=j)
            return true;

        if(sum<m)
            return false;

        if(memoization[i][j]!=-1)
            return memoization[i][j];

        return memoization[i][j]=dp(nums,i+1,j,sum-nums[i],m,memoization) || dp(nums,i,j-1,sum-nums[j],m,memoization); 
    }
};