class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        int runningSum=nums[0];
        int globalMax=nums[0];
        int globalMin=nums[0];
        int globalMaxSum=nums[0];
        int globalMinSum=nums[0];
        for(int i=1;i<nums.size();i++){
            globalMax+=nums[i];
            globalMin+=nums[i];
            runningSum+=nums[i];
            globalMax=max(globalMax,nums[i]);
            globalMin=min(0,nums[i]);
            globalMaxSum=max(globalMaxSum,globalMax);
            globalMinSum=min(globalMinSum,globalMin);
        }
        return max(globalMaxSum,runningSum-globalMinSum);
    }
};




/*


-3  -2  -3

amns=max(-2,);


*/


