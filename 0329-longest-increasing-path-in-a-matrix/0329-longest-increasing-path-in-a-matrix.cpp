class Solution {
public:
    vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        priority_queue<vector<int>> pq;
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                pq.push({matrix[i][j],i,j});
            }
        }
        int ans=INT_MIN;
        while(!pq.empty()){
            int row=pq.top()[1];
            int col=pq.top()[2];
            pq.pop();
            int dpVal=1;
            for(int i=0;i<dir.size();i++){
                int nr=row+dir[i][0];
                int nc=col+dir[i][1];
                if(nr>=0 && nr<m && nc>=0 && nc<n){
                    if(matrix[row][col]<matrix[nr][nc]){
                        dpVal=max(dpVal,dp[nr][nc]+1);
                    }
                }
            }
            dp[row][col]=dpVal;
            ans=max(ans,dpVal);
        }
        return ans;
    }
};