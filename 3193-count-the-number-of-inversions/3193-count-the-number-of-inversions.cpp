class Solution {
public:
    unordered_map<int, int> req;
    vector<vector<int>> memo;

    int solve(int index, int inv) {
        if (index <= 0) {
            return inv == 0 ? 1 : 0;
        }

        if (memo[index][inv] != -1) {
            return memo[index][inv];
        }

        int ans = 0;
        for (int i = 0; i <= min(index, inv); ++i) {
            if (req.count(index) && req[index] != inv) {
                continue;
            }
            ans = (ans + solve(index - 1, inv - i)) % 1000000007;
        }

        return memo[index][inv] = ans;
    }

    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        for (auto& r : requirements) {
            req[r[0]] = r[1];
        }

        memo.assign(n, vector<int>(401, -1));
        return solve(n - 1, req[n - 1]);
    }
};
