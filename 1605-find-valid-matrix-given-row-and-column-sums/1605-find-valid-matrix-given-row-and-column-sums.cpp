class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m=rowSum.size();
        int n=colSum.size();
        vector<vector<int>> mat(m,vector<int>(n));    
        long long total=0;
        for(int i=0;i<m;i++){
            mat[i][0]=rowSum[i];
            total+=rowSum[i];
        }
        for(int j=0;j<n-1;j++){
            fix(mat,m,colSum,j,total);
        }
        return mat;
    }

    void fix(vector<vector<int>>& mat,int m,vector<int>& colSum,int col,long long& total){
        long long finalSum=colSum[col];
        long long excess=total-finalSum;
        for(int i=0;i<m;i++){
            int remove=min(excess,(long long)mat[i][col]);
            mat[i][col+1]=remove;
            mat[i][col]-=remove;
            excess-=remove;
        }
        total-=colSum[col];
        return;
    }
};