class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        // Precompute the max 3 values for each row and their column indices
        vector<vector<pair<int, int>>> max3(m);  // {value, columnIndex}
        
        for (int i = 0; i < m; ++i) {
            // Create a vector of {value, column} pairs for each row
            vector<pair<int, int>> row;
            for (int j = 0; j < n; ++j) {
                row.push_back({board[i][j], j});
            }
            // Sort the row by value in descending order and take the top 3
            sort(row.rbegin(), row.rend());
            for (int k = 0; k < 3 && k < n; ++k) {
                max3[i].push_back(row[k]);
            }
        }

        long long maxSum = LLONG_MIN;

        // Brute-force all combinations of 3 different rows
        for (int row1 = 0; row1 < m; ++row1) {
            for (int row2 = row1 + 1; row2 < m; ++row2) {
                for (int row3 = row2 + 1; row3 < m; ++row3) {
                    // Brute-force all combinations of the top 3 values from each row
                    for (auto [val1, col1] : max3[row1]) {
                        for (auto [val2, col2] : max3[row2]) {
                            if (col2 == col1) continue; // Skip if columns are the same
                            for (auto [val3, col3] : max3[row3]) {
                                if (col3 == col1 || col3 == col2) continue; // Skip if columns are the same
                                // Calculate sum of the chosen cells
                                long long currentSum = (long long)val1 + val2 + val3;
                                maxSum = max(maxSum, currentSum);
                            }
                        }
                    }
                }
            }
        }

        return maxSum;
    }
};
