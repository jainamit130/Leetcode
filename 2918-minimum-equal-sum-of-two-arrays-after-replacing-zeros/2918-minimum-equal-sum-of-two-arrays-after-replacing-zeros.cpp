class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0; long long sum2 = 0;
        int count1 = 0, count2 = 0;
        for(auto n:nums1) {
            sum1 += n;
            count1 += n==0;
        }

        for(auto n:nums2) {
            sum2 += n;
            count2 += n==0;
        }

        long long min1 = sum1 + count1;   // 6
        long long min2 = sum2 + count2;   // 5

        // Case1: min1 is smaller and unincreasable (that is count1 = 0)
        // Case2: min2 is smaller and unincreasable (that is count2 = 0)

        if(min1<min2 && count1==0 || min2<min1 && count2==0) return -1;
        
        return max(min1,min2);

    }
};

/*

2   0   2   0   0


1   4

*/