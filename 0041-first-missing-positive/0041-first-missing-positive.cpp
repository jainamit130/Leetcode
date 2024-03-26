class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int t=nums[i];
            while(t>0 && t<=nums.size() && t!=nums[t-1]){
                int temp=t;
                t=nums[t-1];
                nums[temp-1]=temp;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i+1){
                return i+1;
            }
        }
        return nums.size()+1;
    }
};