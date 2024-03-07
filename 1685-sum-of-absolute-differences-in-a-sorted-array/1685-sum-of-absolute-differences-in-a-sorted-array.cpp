class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int prefix=0;
        int sum=0;
        int size=nums.size();
        vector<int> result(nums.size());
        for(auto n:nums)
            sum+=n;
    
        for(int i=0;i<nums.size();i++){
            result[i]=i*nums[i]-prefix+(sum-prefix-nums[i])-(size-1-i)*nums[i];
            prefix+=nums[i];
        }
        return result;
    }
};