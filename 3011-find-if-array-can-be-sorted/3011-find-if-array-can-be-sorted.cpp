class Solution {
public:
    int countSetBits(int n){
        int bits=0;
        while(n){
            if(n&1){
                bits++;
            }
            n=n>>1;
        }
        return bits;
    }
    bool canSortArray(vector<int>& nums) {
        int lastMax=INT_MIN;
        int lastBitCount = -1;
        int j=0;

        while(j<nums.size()){
            int currBitCount = countSetBits(nums[j]);
            int currMin = nums[j];
            int currMax=nums[j];
            while(j<nums.size() && currBitCount==countSetBits(nums[j])){
                currMax = max(nums[j],currMax);
                currMin = min(nums[j],currMin);
                j++;
            }
            if(lastMax>currMin){
                return false;
            }

            lastBitCount = currBitCount;
            lastMax=currMax;
        }
        return true;
    }
};