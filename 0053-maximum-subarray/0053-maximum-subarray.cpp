class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxSum = INT_MIN;
        for(int i=0;i<nums.size();i++) {
            maxSum = max(nums[i],maxSum);
            if((sum + nums[i])>0) {
                sum += nums[i];
                maxSum = max(sum,maxSum);
            } else {
                sum = 0;
            }
        }
        return maxSum;
    }
};

/*

-2  1   -3  4   -1  2   1   -5  4
                                i

sum = 4
maxSum = 6

*/