class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>> prefix(m,vector<vector<int>>(n,vector<int>(2)));
        prefix[0][0]={0,0};
        //first row 
        int count1=0;
        int count2=0;
        for(int i=0;i<m;i++){
            if(grid[i][0]=='X'){
                count1+=1;
            } else if(grid[i][0]=='Y'){
                count2+=1;
            }
            prefix[i][0]={count1,count2};
        }

        //first col 
        count1=0;
        count2=0;
        for(int j=0;j<n;j++){
            if(grid[0][j]=='X'){
                count1+=1;
            } else if(grid[0][j]=='Y'){
                count2+=1;
            }
            prefix[0][j]={count1,count2};
        }

        //build remaining prefix
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
                if(count1>=1 && count1==count2){
                    ans++;
                }
            }
        }
        return ans;
    }
};

/*







*/