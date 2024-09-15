#include <vector>
#include <unordered_set>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maxValue(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Create 2D arrays of unordered_set to store OR values for left and right parts
        vector<vector<unordered_set<int>>> left(n, vector<unordered_set<int>>(k + 1));
        vector<vector<unordered_set<int>>> right(n, vector<unordered_set<int>>(k + 1));

        // Initialize the sets
        left[0][0].insert(0);
        left[0][1].insert(nums[0]);

        // Fill left DP table with OR results
        for (int i = 1; i < n - k; ++i) {
            left[i][0].insert(0);
            for (int j = 1; j <= k; ++j) {
                left[i][j].insert(left[i - 1][j].begin(), left[i - 1][j].end());
                for (int v : left[i - 1][j - 1]) {
                    left[i][j].insert(v | nums[i]);
                }
            }
        }

        // Initialize right DP table
        right[n - 1][0].insert(0);
        right[n - 1][1].insert(nums[n - 1]);

        int result = 0;

        // Special case for k = 1
        if (k == 1) {
            for (int l : left[n - 2][k]) {
                result = max(result, l ^ nums[n - 1]);
            }
        }

        // Fill right DP table and compute the max XOR
        for (int i = n - 2; i >= k; --i) {
            right[i][0].insert(0);
            for (int j = 1; j <= k; ++j) {
                right[i][j].insert(right[i + 1][j].begin(), right[i + 1][j].end());
                for (int v : right[i + 1][j - 1]) {
                    right[i][j].insert(v | nums[i]);
                }
            }

            // Calculate the maximum XOR by combining left and right
            for (int l : left[i - 1][k]) {
                for (int r : right[i][k]) {
                    result = max(result, l ^ r);
                }
            }
        }

        return result;
    }
};
