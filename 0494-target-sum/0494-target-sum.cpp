class Solution {
public:
    vector<vector<int>> cache;
    int totalSum = 2000;
    int findTargetSumWays(vector<int>& nums, int target) {
        cache.resize(1000*4+1,vector<int>(nums.size()+1,INT_MIN));
        return solve(nums,0,target);
    }

    int solve(vector<int>& nums,int index,int target) {
        if(index>=nums.size()) {
            if(target==0) {
                return 1;
            }
            return 0;
        }

        if(cache[target+totalSum][index]!=INT_MIN) {
            return cache[target+totalSum][index];
        }

        return cache[target+totalSum][index]=solve(nums,index+1,target-nums[index])+solve(nums,index+1,target+nums[index]);
    }
};