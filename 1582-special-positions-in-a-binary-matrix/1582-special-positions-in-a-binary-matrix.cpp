class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<int> colPrefix(n);
        vector<int> rowPrefix(m);
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                rowPrefix[i]+=mat[i][j];
                colPrefix[j]+=mat[i][j];
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(rowPrefix[i]==1 && colPrefix[j]==1){
                    ans++;
                }
            }
        }
        return ans/3;
    }
};