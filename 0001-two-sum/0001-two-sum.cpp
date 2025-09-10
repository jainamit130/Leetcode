class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indices(nums.size());
        iota(indices.begin(),indices.end(),0);
        sort(indices.begin(),indices.end(),[&](auto& lhs,auto& rhs) {
            return nums[lhs]<nums[rhs];
        });
        int i=0,j=nums.size()-1;
        while(i<j) {
            if(nums[indices[i]]+nums[indices[j]]==target) return {indices[i],indices[j]};
            else if((nums[indices[i]]+nums[indices[j]])<target) i++;
            else j--;
        }
        return {};
    }
};