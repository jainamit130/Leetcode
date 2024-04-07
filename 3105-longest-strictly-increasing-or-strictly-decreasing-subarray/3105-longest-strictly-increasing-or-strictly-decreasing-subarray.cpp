class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans=1;
        int len=1;
        int len1=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1])
                len++;
            else{
                ans=max(len,ans);
                len=1;
            }
            if(nums[i]<nums[i-1])
                len1++;
            else{
                ans=max(len1,ans);
                len1=1;
            }
        }
        ans=max(len1,ans);
        ans=max(len,ans);
        return ans;
    }
};


/*


1   4   3   3   2
            i

*/