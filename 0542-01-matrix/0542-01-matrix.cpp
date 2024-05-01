class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> dist(m, vector<int>(n, 1000000));
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(mat[i][j] == 0) {
                    dist[i][j] = 0;
                } else {
                    int left = dist[i][max(0, j-1)];
                    int top  = dist[max(0, i-1)][j];
                    
                    dist[i][j] = min(dist[i][j], 1 + min(left, top));
                }
            }
        }
        
        for(int i = m-1; i>=0; i--) {
            for(int j = n-1; j>=0; j--) {
                if(mat[i][j] == 0) {
                    dist[i][j] = 0;
                } else {
                    int right = dist[i][min(n-1, j+1)];
                    int down  = dist[min(m-1, i+1)][j];
                    
                    dist[i][j] = min(dist[i][j], 1 + min(right, down));
                }
            }
        }
        
        
        return dist;
    }
};
// class Solution {
// public:
//     vector<vector<int>> ans;
//     vector<vector<int>> visited;
    
//     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//         int row = mat.size();
//         int col = mat[0].size();
//         ans.resize(row, vector<int>(col));        
//         for(int i = 0; i < row; i++) {
//             for(int j = 0; j < col; j++) {
//                 if(mat[i][j] == 1) {
//                     ans[i][j] = dfs(i, j, mat);
//                 } else {
//                     ans[i][j] = 0;
//                 }
//             }
//         }
//         return ans;
//     }

//     int dfs(int i, int j, vector<vector<int>>& mat) {
//         if (i < 0 || j < 0 || i >= mat.size() || j >= mat[0].size() || mat[i][j] == 2)
//             return 1e5;
//         if (mat[i][j] == 0)
//             return 0;
//         mat[i][j] = 2;
//         int subAns = INT_MAX;
//         subAns = min(subAns, 1 + dfs(i - 1, j, mat));
//         subAns = min(subAns, 1 + dfs(i + 1, j, mat));
//         subAns = min(subAns, 1 + dfs(i, j - 1, mat));
//         subAns = min(subAns, 1 + dfs(i, j + 1, mat));
//         mat[i][j]=1;
//         return subAns;
//     }
// };