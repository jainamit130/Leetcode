class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0;int j=0;
        bool available=true;
        int ans=0;
        int count=0;
        while(j<nums.size() && i<=j){
            if(available && nums[j]==0){
                available=false;
                j++;
            } else {
                if(nums[j]){
                    j++;
                    count++;
                    ans=max(ans,count);
                }
                else {
                    if(nums[i]==1){
                        i++;
                        count--;
                    } else {
                        i++;
                        available=true;
                    }
                }
            }
        }
        if(ans==nums.size())
            ans--;
        return ans;
    }
};