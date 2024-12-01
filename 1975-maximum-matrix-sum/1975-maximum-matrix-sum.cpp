class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int br=0, min=abs(matrix[0][0]);
        long long z=0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (matrix[i][j]<0) {
                    matrix[i][j]*=-1;
                    br++;
                }
                z+=matrix[i][j];
                if (matrix[i][j]<min) min=matrix[i][j];
            }
        }
        if (br%2==0) return z;
        return z-2*min;
    }
};