class Solution {
public:
    unordered_map<int,unordered_map<int,int>> dp;
    int makeStringGood(string s) {
        unordered_map<int, int> mp;
        for (auto ch : s) {
            mp[ch - 'a']++;
        }

        int maxC = 0;
        for (auto [_, count] : mp) {
            maxC = max(maxC, count);
        }

        int ans = INT_MAX;

        for (int i = 0; i <= maxC; i++) {
            dp.clear();
            ans = min(ans, solve(0, 0, i, mp));
        }
        return ans;
    }

    int solve(int index, int leftOver, int target, unordered_map<int, int> &mp) {
        if (index >= 26) {
            return 0;
        }
        if (dp[index].count(leftOver)) {
            return dp[index][leftOver];
        }

        int ans = INT_MAX;
        int current = mp[index];

        if (current == target) {
            ans = min(ans, solve(index + 1, 0, target, mp));
        } else if (current > target) {
            ans = min(ans, solve(index + 1, current - target, target, mp) + current - target);
        } else {
            ans = min({
                ans,
                solve(index + 1, 0, target, mp) + max(target - (current + leftOver), 0),
                solve(index + 1, current, target, mp) + current
            });
        }

        return dp[index][leftOver] = ans;
    }
};
