class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int c=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)
            {    c++;continue;}
            else {
                nums[i-c]=nums[i];
            }
        }
        for(int i=nums.size()-1;i>nums.size()-c-1;i--){
            nums[i]=0;
        }
        return;
    }
};