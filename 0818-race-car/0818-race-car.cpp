#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    int racecar(int target) {
        vector<int> dp(target + 1, -1);
        return racecarHelper(target, dp);
    }

private:
    int racecarHelper(int target, vector<int>& dp) {
        if (dp[target] >= 0) {
            return dp[target];
        }

        int n = floor(log2(target)) + 1;
        if (target == (1 << n) - 1) {
            dp[target] = n;
        } else {
            dp[target] = n + 1 + racecarHelper((1 << n) - 1 - target, dp);
            for (int i = 0; i < n - 1; ++i) {
                dp[target] = min(dp[target], n + i + 1 + racecarHelper(target - (1 << (n - 1)) + (1 << i) + 1, dp));
            }
        }
        return dp[target];
    }
};



/*


0   1   2   3   4   
0   1   3   7   15  


    A   A   A
0   1   3   7

Diff = 2


    A   A   A   A
0   1   3   7   15  






*/