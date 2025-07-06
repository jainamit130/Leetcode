class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> prefix(grid.size(),vector<int>(grid[0].size()));
        //Building 1st Col
        prefix[0][0]=grid[0][0];
        for(int i=1;i<m;i++){
            prefix[i][0]=prefix[i-1][0]+grid[i][0];
        }
        
        //Building 1st Row
        for(int j=1;j<n;j++){
            prefix[0][j]=prefix[0][j-1]+grid[0][j];
        }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                prefix[i][j]=prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1]+grid[i][j];
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int count1=prefix[i][j];
                if(count1<=k){
                    ans++;
                }
            }
        }
        return ans*2;
    }
};