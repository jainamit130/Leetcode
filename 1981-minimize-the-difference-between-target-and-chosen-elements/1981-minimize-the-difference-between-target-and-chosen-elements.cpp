class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int m = mat.size();
        int n = mat[0].size();
        unordered_set<int> possibleSums = {0}; // Start with 0 as the only possible sum

        for (const auto& row : mat) {
            unordered_set<int> newSums;
            for (int sum : possibleSums) {
                for (int num : row) {
                    newSums.insert(sum + num);
                }
            }
            possibleSums = std::move(newSums);
        }

        int closestDifference = INT_MAX;
        for (int sum : possibleSums) {
            closestDifference = min(closestDifference, abs(target - sum));
        }

        return closestDifference;
    }
};
