class Solution {
public:
    vector<vector<int>> cache;
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        cache.resize(matrix.size()+1,vector<int>(matrix[0].size(),INT_MAX));
        for(int i=0;i<matrix[0].size();i++) ans = min(ans,solve(matrix,0,i));
        return ans;
    }

    int solve(vector<vector<int>>& matrix,int row,int col) {
        if(row>=matrix.size()) return 0;
        if(cache[row][col]!=INT_MAX) return cache[row][col];
        int ans = 1e5;
        ans = min(ans, matrix[row][col] + solve(matrix,row+1,col));
        if(col>0) ans = min(ans, matrix[row][col] + solve(matrix,row+1,col-1));
        if(col<matrix[0].size()-1) ans = min(ans, matrix[row][col] + solve(matrix,row+1,col+1));
        return cache[row][col]=ans;
    }
};