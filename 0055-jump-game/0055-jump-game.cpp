class Solution {
public:
    bool canJump(vector<int>& nums) {
        int nearestTrue=nums.size()-1;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]>=(nearestTrue-i)){
                nearestTrue=i;
            } 
        }
        return nearestTrue==0;
    }
};