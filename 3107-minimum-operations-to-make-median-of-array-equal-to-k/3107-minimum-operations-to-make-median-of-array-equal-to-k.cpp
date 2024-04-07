class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            if(i<nums.size()/2){
                if(nums[i]>k){
                    ans+=nums[i]-k;
                }
            } else if(i>nums.size()/2) {
                if(nums[i]<k){
                    ans+=k-nums[i];
                }
            } else {
                ans+=abs(nums[i]-k);
            }
        }
        return ans;
    }
};




/*

k=4
2   6   6   8   9
  
2   4   4   8   9
firstGreaterIndex = 1

k=7
2   3   4   6   11

2   3   7   7   11
firstGreaterIndex = 4


*/