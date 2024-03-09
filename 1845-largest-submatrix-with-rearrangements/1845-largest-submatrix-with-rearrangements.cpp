class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        int ans=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]){
                    if(i-1>=0)
                        matrix[i][j]=matrix[i-1][j]+1;
                }
                else
                    matrix[i][j]=0;
            }
            vector<int> copy=matrix[i];
            sort(copy.begin(),copy.end());
            for(int i=copy.size()-1;i>=0;i--){
                int base=copy.size()-i;
                ans=max(copy[i]*(base),ans);
            }
        }
        return ans;
    }   
};