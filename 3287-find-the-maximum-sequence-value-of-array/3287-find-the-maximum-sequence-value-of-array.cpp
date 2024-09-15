class Solution {
public:
    int maxValue(vector<int>& nums, int k) {
        int n = nums.size();

        vector<vector<vector<bool>>> left(n, vector<vector<bool>>(k + 1, vector<bool>(128, false)));
        vector<vector<vector<bool>>> right(n, vector<vector<bool>>(k + 1, vector<bool>(128, false)));

        // Initialize the bitmask arrays
        left[0][0][0] = true;
        left[0][1][nums[0]] = true;

        // Fill left DP table with OR results using bitmasking
        for (int i = 1; i < n - k; ++i) {
            left[i][0][0] = true;
            for (int j = 1; j <= k; ++j) {
                for (int v = 0; v < 128; ++v) {
                    // Carry over previous OR results
                    if (left[i - 1][j][v]) left[i][j][v] = true;

                    // Compute new OR results by including nums[i]
                    if (left[i - 1][j - 1][v]) {
                        left[i][j][v | nums[i]] = true;
                    }
                }
            }
        }

        // Initialize right DP table with OR results
        right[n - 1][0][0] = true;
        right[n - 1][1][nums[n - 1]] = true;

        int result = 0;

        // Special case for k = 1
        if (k == 1) {
            for (int l = 0; l < 128; ++l) {
                if (left[n - 2][k][l]) {
                    result = max(result, l ^ nums[n - 1]);
                }
            }
        }

        // Fill right DP table and compute the max XOR
        for (int i = n - 2; i >= k; --i) {
            right[i][0][0] = true;
            for (int j = 1; j <= k; ++j) {
                for (int v = 0; v < 128; ++v) {
                    // Carry over previous OR results
                    if (right[i + 1][j][v]) right[i][j][v] = true;

                    // Compute new OR results by including nums[i]
                    if (right[i + 1][j - 1][v]) {
                        right[i][j][v | nums[i]] = true;
                    }
                }
            }
        }

        for(int i=1;i<n;i++){
            for (int g = 0; g < 128; ++g) {
                if(left[i-1][k][g]){
                    for (int v = 0; v < 128; ++v) {
                        if(right[i][k][v])
                            result=max(result,g^v);
                    }
                }
            }
        }

        return result;
    }
};
