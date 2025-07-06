class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = -1;
        int minNum = nums[0];
        for(int i=1;i<nums.size();i++) {
            if(nums[i]==minNum) continue;
            ans = max(ans,nums[i]-minNum);
            minNum = min(minNum,nums[i]);
        }
        return ans;
    }
};