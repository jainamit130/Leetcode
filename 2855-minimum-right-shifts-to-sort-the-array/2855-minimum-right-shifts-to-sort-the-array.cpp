class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int ans=0;
        int count=1;
        if(nums.back()>nums[0]){
            count=0;    
        }
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i] && count){
                ans=nums.size()-i;
                count--;
            } else if(nums[i-1]>nums[i] && count==0){
                return -1;
            }
        }
        return ans;
    }
};