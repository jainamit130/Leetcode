class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int count = 1;
        int maxVal = nums[0];
        int ans=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                count++;
            } else {
                if(nums[i-1]>=maxVal){
                    ans=max(ans,count);
                    maxVal = nums[i-1];
                }
                count=1;
            }
        }
        return ans;
    }
};



/*

1    2   3   3   2   2   

    0   0   0   1
    0   0   1   0
    0   0   1   1
    0   0   1   1
    0   0   1   0
    0   0   1   0
-----------------------
    0   0   0   0



*/