class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n= nums.size();
        vector<int> incSizes(n,1);
        int i=n-2;
        while(i>=0){
            if(nums[i]<nums[i+1]) {
                incSizes[i] = incSizes[i+1]+1;
            } 
            i--;
        } 

        for(int i=0;i<n-k;i++) {
            if(incSizes[i]>=k && incSizes[i+k]>=k){
                return true;
            }
        }
        return false;
    }
};