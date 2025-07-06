class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long totalSum = accumulate(nums.begin(),nums.end(),0);
        int ans = 0;
        long long sum = 0;
        for(int i=0;i<nums.size()-1;i++) {
            sum+=nums[i];
            totalSum-=nums[i];
            if(sum>=totalSum) {
                ans++;
            }
        }
        return ans;
    }
};