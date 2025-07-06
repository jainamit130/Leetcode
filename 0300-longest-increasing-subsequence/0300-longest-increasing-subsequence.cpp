class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> buckets;
        for(auto n:nums) {
            int index = lower_bound(buckets.begin(),buckets.end(),n)-buckets.begin();
            if(buckets.size()<index+1) {
                buckets.push_back(n);
            } else {
                buckets[index] = n;
            }
        }
        return buckets.size();
    }
};


/*

10  9   2   5   3   7   101   18




*/