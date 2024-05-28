class Solution {
public:
    int ans=0;
    int findTargetSumWays(vector<int>& nums, int target) {
        solve(nums,target,0,0);
        return ans;
    }

    void solve(vector<int>& nums,int target,int currSum,int index){
        if(index>=nums.size()){
            if(currSum==target)
                ans++;
            return;
        }
    
        //minus
        solve(nums,target,currSum-nums[index],index+1);
        //plus
        solve(nums,target,currSum+nums[index],index+1);
        return;
    }
};

/*
x

target


*/