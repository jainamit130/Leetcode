class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1)
            return 0;
        int i=0;
        int j=0;
        long long prod=1;
        int ans=0;
        while(j<nums.size()){
            prod*=nums[j];
            while(prod>=k){
                prod/=nums[i];
                i++;
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
};

/*
8
5
2   2   2   2   2   2
    i
            j
*/