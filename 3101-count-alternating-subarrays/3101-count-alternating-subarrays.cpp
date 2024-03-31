class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int i = 0, j = 0;
        long long ans = 0;
        int size = 1;

        while (j < nums.size()) {
            if (j + 1 < nums.size() && nums[j + 1] != nums[j]) {
                j++;
                size++;
            } else {
                ans += ((long long)size * (size + 1) / 2);
                size = 1;
                j++;
            }
        }
        return ans;
    }
};