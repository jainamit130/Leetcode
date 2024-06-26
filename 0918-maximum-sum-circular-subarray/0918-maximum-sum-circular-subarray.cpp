class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int runningSum=nums[0];
        int currMax=nums[0];
        int currMin=nums[0];
        int globalMax=nums[0];
        int globalMin=nums[0];
        for(int i=1;i<nums.size();i++){
            currMax+=nums[i];
            currMin+=nums[i];
            runningSum+=nums[i];
            currMax=max(currMax,nums[i]);
            currMin=min(currMin,nums[i]);
            globalMax=max(globalMax,currMax);
            globalMin=min(globalMin,currMin);
        }
        return (globalMax>0)?max(globalMax,runningSum-globalMin):globalMax;
    }
};




/*


-3  -2  -3

amns=max(-2,);


*/


