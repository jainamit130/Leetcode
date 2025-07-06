class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
       int repeated=nums[0];
       int totalSum = 0;
       int n = nums.size();
       for(int i=0;i<n;i++) {
            int truePaceIndex = abs(nums[i])-1;
            totalSum += abs(nums[i]);
            if(nums[truePaceIndex]<0) repeated = nums[i];
            else nums[truePaceIndex]*=-1;
       }

        int correctSum = (n*(n+1))/2;
        int missing = abs((totalSum-repeated)-correctSum);
        return {repeated,missing};
    }
};
