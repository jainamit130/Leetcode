class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int globalMax=nums[0];
        int globalMin=nums[0];
        int currentMax=0;
        int currentMin=0;
        int total=0;
        for(auto n:nums){
            total+=n;
            currentMax=max(n,currentMax+n);
            globalMax=max(globalMax,currentMax);
            currentMin=min(n,currentMin+n);
            globalMin=min(globalMin,currentMin);
        }
        if(globalMax<0)
            return globalMax;
        return max(total-globalMin,globalMax);
    }
};