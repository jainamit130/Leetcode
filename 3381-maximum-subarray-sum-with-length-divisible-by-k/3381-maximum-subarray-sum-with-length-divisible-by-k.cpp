class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<long long, long long>> dp(n + 1, {LLONG_MIN, LLONG_MIN});
        vector<long long> prefix(n + 2);
        prefix[n] = nums[n - 1];
        long long ans = LLONG_MIN;
        if (k == 1) {
            ans = nums[n - 1];
            dp[n - 1] = {nums[n - 1], LLONG_MIN};
        }
        for (int i = n - 2; i >= 0; i--) {
            prefix[i + 1] = prefix[i + 2] + nums[i];
            if (i + k <= n) {
                long long take = prefix[i + 1] - prefix[i + k + 1];

                long long option1 = dp[i + k].first == LLONG_MIN
                                        ? take
                                        : dp[i + k].first + take;
                long long option2 = dp[i + k].second;

                dp[i] = {std::max(option1, take),
                         std::max(dp[i + k].first, option2)};

                ans = std::max({dp[i].first, dp[i].second, ans});
            }
        }
        return ans;
    }
};