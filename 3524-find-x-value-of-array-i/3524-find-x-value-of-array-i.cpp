class Solution {
public:
    using ll = long long;
    
    vector<ll> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll> result(k, 0);

        for (int targetRem = 0; targetRem < k; ++targetRem) {
            vector<vector<ll>> memo(n, vector<ll>(k + 1, -1));
            result[targetRem] = countSubarrays(0, -1, targetRem, nums, k, memo);
        }

        return result;
    }

private:
    ll countSubarrays(int index, int currentProduct, int targetRem,
                      const vector<int>& nums, int k,
                      vector<vector<ll>>& memo) {
        int n = nums.size();
        if (index == n) return 0;

        int dpKey = currentProduct + 1;
        if (memo[index][dpKey] != -1) return memo[index][dpKey];

        ll ways = 0;

        if (currentProduct == -1) {
            int newProduct = nums[index] % k;
            if (newProduct == targetRem) ways += 1;

            ways += countSubarrays(index + 1, newProduct, targetRem, nums, k, memo);

            ways += countSubarrays(index + 1, -1, targetRem, nums, k, memo);
        } else {
            int newProduct = (1LL * currentProduct * nums[index]) % k;
            if (newProduct == targetRem) ways += 1;

            ways += countSubarrays(index + 1, newProduct, targetRem, nums, k, memo);
        }

        return memo[index][dpKey] = ways;
    }
};
