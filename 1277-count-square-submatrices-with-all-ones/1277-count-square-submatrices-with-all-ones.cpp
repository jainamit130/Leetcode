class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ret = 0;  
        
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {

                if (matrix[i][j] == 1) {
                    int top = i == 0 ? 0 : matrix[i - 1][j];
                    int left = j == 0 ? 0 : matrix[i][j - 1];
                    int diag = (i == 0 || j == 0) ? 0 : matrix[i - 1][j - 1];

                    matrix[i][j] += min(min(top, left), diag);
                    
                    ret += matrix[i][j];
                }
            }
        }
        return ret;  
    }
};