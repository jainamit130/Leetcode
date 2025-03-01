class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> modifiedNums;

        // Step 1: Apply operations on the array
        for (int index = 0; index < n - 1; index++) {
            if (nums[index] == nums[index + 1] && nums[index] != 0) {
                nums[index] *= 2;
                nums[index + 1] = 0;
            }
        }

        // Step 2: Move non-zero elements to the front
        for (int num : nums) {
            if (num != 0) {
                modifiedNums.push_back(num);
            }
        }

        // Step 3: Append zeros to maintain the original size
        while (modifiedNums.size() < n) {
            modifiedNums.push_back(0);
        }

        return modifiedNums;
    }
};