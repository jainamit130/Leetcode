class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum=0;
        int d=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            d+=i*nums[i];
        }
        int ans=d;
        for(int i=nums.size()-1;i>=0;i--){
            d+=sum-nums.size()*nums[i];
            ans=max(ans,d);
        }
        return ans;
    }
};