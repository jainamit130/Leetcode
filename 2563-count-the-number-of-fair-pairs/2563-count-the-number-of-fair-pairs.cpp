class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        vector<int> sortedNums;
        int ans = 0;
        for(auto n:nums){
            int lowerLimit = lower-n;
            int upperLimit = upper-n;
            int index1 = lower_bound(sortedNums.begin(),sortedNums.end(),lowerLimit)-sortedNums.begin();
            int index2 = upper_bound(sortedNums.begin(),sortedNums.end(),upperLimit)-sortedNums.begin();
            ans+=index2-index1;
            sortedNums.push_back(n);
            sort(sortedNums.begin(),sortedNums.end());
        }
        return ans;
    }
};

/*
nums[j] = 4

then i want 
-1<=nums[i]<=2



*/