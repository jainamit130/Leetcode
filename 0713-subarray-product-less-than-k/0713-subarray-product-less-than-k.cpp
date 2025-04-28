class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        int ans = 0;
        int i=0,j=0;
        long long prod = 1;
        while(j<nums.size()) {
            while(j<nums.size() && prod<k) {
               ans += j-i;
               prod *= nums[j];
               j++; 
            }

            while(i<j && prod>=k) {
                prod/=nums[i];
                i++;
            }
        }
        if(prod<k) ans+=j-i;
        return ans;
    }
};