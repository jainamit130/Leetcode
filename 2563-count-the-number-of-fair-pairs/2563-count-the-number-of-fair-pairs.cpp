class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        long long ans = 0;
        for(int i=0;i<nums.size();i++){
            int index1 = lower_bound(nums.begin(),nums.begin()+i,lower-nums[i])-nums.begin();
            int index2 = upper_bound(nums.begin(),nums.begin()+i,upper-nums[i])-nums.begin();
            ans+=index2-index1;
        }
        return ans;
    }
};