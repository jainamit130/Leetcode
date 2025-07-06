class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1,
                                    vector<vector<int>>& nums2) {
        map<int, int> keyToSum;

        // Copying the array nums1 to the map.
        for (auto nums : nums1) {
            keyToSum[nums[0]] = nums[1];
        }

        // Adding the values to existing keys or create new entries.
        for (auto nums : nums2) {
            keyToSum[nums[0]] += nums[1];
        }

        vector<vector<int>> mergedArray;
        for (auto it : keyToSum) {
            mergedArray.push_back({it.first, it.second});
        }

        return mergedArray;
    }
};