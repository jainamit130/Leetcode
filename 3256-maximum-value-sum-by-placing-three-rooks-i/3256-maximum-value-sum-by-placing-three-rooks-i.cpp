class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<pair<int, int>>> max3(m);  
        
        for (int i = 0; i < m; ++i) {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  
            
            for (int j = 0; j < n; ++j) {
                pq.push({board[i][j], j});
                if (pq.size() > 3) {
                    pq.pop();
                }
            }
            
            while (!pq.empty()) {
                max3[i].push_back(pq.top());
                pq.pop();
            }
        }

        long long maxSum = LLONG_MIN;

        for (int row1 = 0; row1 < m; ++row1) {
            for (int row2 = row1 + 1; row2 < m; ++row2) {
                for (int row3 = row2 + 1; row3 < m; ++row3) {
                    for (auto [val1, col1] : max3[row1]) {
                        for (auto [val2, col2] : max3[row2]) {
                            if (col2 == col1) continue; 
                            for (auto [val3, col3] : max3[row3]) {
                                if (col3 == col1 || col3 == col2) continue; 
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