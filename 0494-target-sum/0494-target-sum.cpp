class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums,target,0,0);
    }

    int solve(vector<int>& nums,int target,int currSum,int index){
        if(index>=nums.size()){
            if(currSum==target)
                return 1;
            else
                return 0;
        }
    
        int subtract = solve(nums,target,currSum-nums[index],index+1);
        int add = solve(nums,target,currSum+nums[index],index+1);
        return subtract+add;
    }
};

/*
x

target


*/