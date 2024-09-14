class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int count = 1;
        int maxVal = nums[0];
        int ans=1;
        int val=nums[0];
        for(int i=1;i<=nums.size();i++){
            if(i<nums.size() && nums[i]==nums[i-1]){
                count++;
            } else {
                if(val>maxVal){
                    ans=count;
                    maxVal=val;
                } else if(val==maxVal){
                    ans=max(ans,count);
                }
                if(i==nums.size()){
                    break;
                }
                val=nums[i];
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