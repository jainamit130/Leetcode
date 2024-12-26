class Solution {
public:
    vector<vector<int>> cache;
    int totalSum = 0;
    int findTargetSumWays(vector<int>& nums, int target) {
        totalSum = accumulate(nums.begin(),nums.end(),0);
        cache.resize(totalSum*4+1,vector<int>(nums.size()+1,INT_MIN));
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