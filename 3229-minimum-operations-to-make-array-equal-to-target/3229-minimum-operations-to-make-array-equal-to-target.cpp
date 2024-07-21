class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        vector<int> diff;
        for (int i = 0; i < nums.size(); i++) {
            diff.push_back(target[i] - nums[i]);
        }

        long long ans = abs(diff[0]);
        int prev = abs(diff[0]);
        for (int i = 1; i < nums.size(); i++) {
            if ((diff[i - 1] < 0 && diff[i] < 0) ||
                (diff[i - 1] > 0 && diff[i] > 0)) {
                if (prev < abs(diff[i])) {
                    ans += abs(diff[i]) - abs(prev);
                }
            } else {
                ans += abs(diff[i]);
            }

            prev = abs(diff[i]);
        }
        return ans;
    }
};