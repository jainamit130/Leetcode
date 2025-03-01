class Solution {
public:
    vector<vector<int>> cache;
    int minCost(vector<int>& nums) {
        cache.resize(nums.size()+1,vector<int>(nums.size()+1,-1));
        return solve(1,0,nums);
    }

    int solve(int index,int leftIndex,vector<int>& nums) {
        if(index==nums.size()-1) {
            return max(nums[index],nums[leftIndex]);
        }

        if(index==nums.size()-2) {
            return max({nums[index],nums[index+1],nums[leftIndex]});
        }

        if(index>=nums.size()) return nums[leftIndex];

        if(cache[index][leftIndex]!=-1) return cache[index][leftIndex];
        int ans = INT_MAX;
        ans = min(ans,max(nums[index],nums[index+1])+solve(index+2,leftIndex,nums));
        ans = min(ans,max(nums[leftIndex],nums[index])+solve(index+2,index+1,nums));
        ans = min(ans,max(nums[leftIndex],nums[index+1])+solve(index+2,index,nums));

        return cache[index][leftIndex]=ans;
    }
};