class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> cache(nums.size()+1, vector<int>(2 * sum + 1, INT_MIN));
        return solve(nums,target,0,0,sum,cache);
    }

    int solve(vector<int>& nums,int target,int currSum,int index,int sum,vector<vector<int>>& cache){
        if(index>=nums.size()){
            if(currSum==target)
                return 1;
            else
                return 0;
        }

        int adjustedSum = currSum + sum;

        if(cache[index][adjustedSum]!=INT_MIN)
            return cache[index][adjustedSum];
    
        int subtract = solve(nums,target,currSum-nums[index],index+1,sum,cache);
        int add = solve(nums,target,currSum+nums[index],index+1,sum,cache);
        return cache[index][adjustedSum]=subtract+add;
    }
};

/*
x

target


*/