class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<3)
            return false;
        int num1=INT_MAX,num2=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int num3=nums[i];
            if(num3<=num1)
                num1=num3;
            else if(num3<=num2){
                num2=num3;
            }else{
                return true;
            }
        }
        return false;
    }
};