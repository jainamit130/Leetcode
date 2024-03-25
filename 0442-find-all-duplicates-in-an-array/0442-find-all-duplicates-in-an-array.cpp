class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int n=abs(nums[i]);
            if(nums[n-1]<0){
                ans.push_back(n);
            } else {
                nums[n-1]*=-1;
            }
        }
        return ans;
    }
};