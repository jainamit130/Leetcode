class Solution {
public:
    vector<vector<int>> dir={{0,1},{1,0},{-1,0},{0,-1}};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> cache(matrix.size()+1,vector<int>(matrix[0].size()+1,-1));
        vector<vector<int>> adj;
        int ans=1;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                ans=max(ans,dfs(i,j,matrix,cache));
            }
        }
        return ans;
    }

    bool isValid(int row,int col,int m,int n){
        if(row<0 || row>=m || col<0 || col>=n)
            return false;
        return true;
    }

    int dfs(int row,int col,vector<vector<int>>& matrix,vector<vector<int>>& cache){
        if(!isValid(row,col,matrix.size(),matrix[0].size())){
            return 0;
        }

        if(cache[row][col]!=-1){
            return cache[row][col];
        }

         cache[row][col]=1;
        for(int i=0;i<dir.size();i++){
            int newr=row+dir[i][0];
            int newc=col+dir[i][1];
            if(isValid(newr,newc,matrix.size(),matrix[0].size()) && matrix[newr][newc]>matrix[row][col]){
                 cache[row][col]=max( cache[row][col],1+dfs(newr,newc,matrix,cache));
            }
        }
        return  cache[row][col];
    }
};