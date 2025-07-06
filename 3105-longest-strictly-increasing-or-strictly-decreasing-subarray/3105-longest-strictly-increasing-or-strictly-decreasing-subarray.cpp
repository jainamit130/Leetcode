class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1;
        int strictlyIncCount = 1;
        int strictlyDecCount = 1;
        for(int i=1;i<nums.size();i++) {
            if(nums[i]<nums[i-1]) {
                strictlyDecCount++;
                strictlyIncCount=1;
            } else if (nums[i]>nums[i-1]) {
                strictlyIncCount++;
                strictlyDecCount=1;
            } else {
                strictlyDecCount=1;
                strictlyIncCount=1;
            }
            ans = max({ans,strictlyDecCount,strictlyIncCount});
        }
        return ans;
    }
};