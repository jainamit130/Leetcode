class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        int ans=0;
        vector<int> colCountofConsecutive1(col);
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j])
                    colCountofConsecutive1[j]++;
                else
                    colCountofConsecutive1[j]=0;
            }
            vector<int> copy=colCountofConsecutive1;
            sort(copy.begin(),copy.end());
            for(int i=copy.size()-1;i>=0;i--){
                int base=copy.size()-i;
                ans=max(copy[i]*(base),ans);
            }
        }
        return ans;
    }   
};