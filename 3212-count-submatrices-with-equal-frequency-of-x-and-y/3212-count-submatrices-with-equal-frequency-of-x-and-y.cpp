class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>> prefix(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(2)));
        //Building 1st Col
        int count1=0;
        int count2=0;
        for(int i=0;i<m;i++){
            if(grid[i][0]=='X'){
                count1++;
            } else if(grid[i][0]=='Y'){
                count2++;
            }
            prefix[i][0][0]=count1;
            prefix[i][0][1]=count2;
        }
        
        //Building 1st Row
        count1=0;
        count2=0;
        for(int j=0;j<n;j++){
            if(grid[0][j]=='X'){
                count1++;
            } else if(grid[0][j]=='Y'){
                count2++;
            }
            prefix[0][j][0]=count1;
            prefix[0][j][1]=count2;
        }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                count1=0,count2=0;
                if(grid[i][j]=='X'){
                    count1=1;
                } else if(grid[i][j]=='Y'){
                    count2=1;
                }
                prefix[i][j][0]=prefix[i-1][j][0]+prefix[i][j-1][0]-prefix[i-1][j-1][0]+count1;
                prefix[i][j][1]=prefix[i-1][j][1]+prefix[i][j-1][1]-prefix[i-1][j-1][1]+count2;
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                count1=prefix[i][j][0];
                count2=prefix[i][j][1];
                if(count1>=1 && count2==count1){
                    ans++;
                }
            }
        }
        return ans;
    }
};