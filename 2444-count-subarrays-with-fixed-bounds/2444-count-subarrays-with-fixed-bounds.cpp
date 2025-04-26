class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int minPosition=-1,maxPosition=-1,culpritIndex=-1;
        long long ans=0;
        int i=0;
        while(i<nums.size()){
            if(nums[i]==minK){
                minPosition=i;
            } 
            if(nums[i]==maxK){
                maxPosition=i;
            } 
            if(nums[i]>maxK || nums[i]<minK){
                culpritIndex=i;
            }
            auto smaller=min(minPosition,maxPosition);
            auto temp=smaller-culpritIndex;
            ans+=(temp<=0)?0:temp;
            i++;
        }
        return ans;
    }
};
/*


1   3   5   2   7   5
i




*/