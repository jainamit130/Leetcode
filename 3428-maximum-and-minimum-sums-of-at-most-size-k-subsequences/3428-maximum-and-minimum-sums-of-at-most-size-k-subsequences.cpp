#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int mod = 1e9 + 7;
    vector<long long> factorials;

    int minMaxSums(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        // Precompute factorials and inverse factorials
        factorials.resize(n + 1, 1);
        for (int i = 2; i <= n; i++) {
            factorials[i] = (factorials[i - 1] * i) % mod;
        }

        int ans = 0;

        // Calculate contributions from the minimum elements
        for (int i = 0; i < n; i++) {
            int n1 = i;  // Number of elements before nums[i]
            // We need to calculate combinations choosing up to k-1 elements from n1 elements
            for (int r = 0; r < min(k, n1 + 1); r++) {
                ans = (ans + (nCr(n1, r) * 1LL * nums[i]) % mod) % mod;
            }
        }

        // Calculate contributions from the maximum elements
        for (int i = 0; i < n; i++) {
            int n2 = n - i - 1;  // Number of elements after nums[i]
            // We need to calculate combinations choosing up to k-1 elements from n2 elements
            for (int r = 0; r < min(k, n2 + 1); r++) {
                ans = (ans + (nCr(n2, r) * 1LL * nums[i]) % mod) % mod;
            }
        }

        return ans;
    }

    long long nCr(int n, int r) {
        if (r > n) return 0;
        return factorials[n] * inverseFact(factorials[r], mod) % mod * inverseFact(factorials[n - r], mod) % mod;
    }

    long long inverseFact(long long n, int mod) {
        return binaryExp(n, mod - 2, mod);
    }

    long long binaryExp(long long base, int exp, int mod) {
        long long prod = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                prod = (prod * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return prod;
    }
};
