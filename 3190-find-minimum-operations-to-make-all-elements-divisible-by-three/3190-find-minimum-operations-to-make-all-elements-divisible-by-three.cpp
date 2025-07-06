class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            nums[i]=nums[i]%3;
            ans+=min(abs(0-nums[i]),abs(3-nums[i]));
        }
        return ans;
    }
};