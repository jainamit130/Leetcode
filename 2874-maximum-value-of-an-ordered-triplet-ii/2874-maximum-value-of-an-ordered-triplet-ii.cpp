class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        int maxDiff = 0;
        int maxVal = 0;
        long long ans = 0;
        for(int i=0;i<n;i++) {
            ans = max(ans,1LL*maxDiff*nums[i]);
            maxDiff = max(maxVal-nums[i],maxDiff);
            maxVal = max(maxVal,nums[i]);
        }
        return ans;
    }
};