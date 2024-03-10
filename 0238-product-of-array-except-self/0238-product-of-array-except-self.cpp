class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size()+2);
        vector<int> postfix(nums.size()+2);
        prefix[0]=1;prefix[nums.size()+1]=1;
        postfix[0]=1;postfix[nums.size()+1]=1;
        int prod=1;
        for(int i=1;i<=nums.size();i++){
            prod*=nums[i-1];
            prefix[i]=prod;
        }
        prod=1;
        for(int j=nums.size();j>=1;j--){
            prod*=nums[j-1];
            postfix[j]=prod;
        }
        for(int i=1;i<=nums.size();i++)
            nums[i-1]=prefix[i-1]*postfix[i+1];
        return nums;
    }
};