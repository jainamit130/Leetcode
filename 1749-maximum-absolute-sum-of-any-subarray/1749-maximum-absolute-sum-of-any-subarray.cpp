class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int minPrefixSum = INT_MAX, maxPrefixSum = INT_MIN;
        int prefixSum = 0, maxAbsSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            // Prefix sum from index 0 to i
            prefixSum += nums[i];

            // Minimum & Maximum prefix sum we have seen so far
            minPrefixSum = min(minPrefixSum, prefixSum);
            maxPrefixSum = max(maxPrefixSum, prefixSum);

            if (prefixSum >= 0) {
                // If the prefixSum is positive, we will get the difference
                // between prefixSum & minPrefixSum
                maxAbsSum =
                    max(maxAbsSum, max(prefixSum, prefixSum - minPrefixSum));
            } else if (prefixSum <= 0) {
                // If the prefixSum is negative, we will get the absolute
                // difference between prefixSum & maxPrefixSum
                maxAbsSum = max(maxAbsSum, max(abs(prefixSum),
                                               abs(prefixSum - maxPrefixSum)));
            }
        }

        return maxAbsSum;
    }
};