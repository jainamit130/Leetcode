class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int one=0,two=0,three=0;
        /*
        5 possibilities
        1st Possibility
        ------------
        |    (1)    |
        |           |
        ------------
        | (2) | (3) |
        |     |     |
        -------------
        */
        int ans=INT_MAX;
        for(int i=0;i<m;i++){
            one=minimumArea(grid,0,i,0,n-1);
            for(int j=0;j<n;j++){
                two=minimumArea(grid,i+1,m-1,0,j);
                three=minimumArea(grid,i+1,m-1,j+1,n-1);
                ans=min(ans,one+two+three);
            }
        }

        /*
        2nd Possibility
        -------------
        |     | (2) |
        |     |     |
        | (1) -------
        |     |     |
        |     | (3) |
        -------------
        */

        for(int j=0;j<n;j++){
            one=minimumArea(grid,0,m-1,0,j);
            for(int i=0;i<m;i++){
                two=minimumArea(grid,0,i,j+1,n-1);
                three=minimumArea(grid,i+1,m-1,j+1,n-1);
                ans=min(ans,one+two+three);
            }
        }

        /*
        3rd Possibility
        -------------
        |     |     |
        | (2) |     |
        ------- (1) |
        |     |     |
        | (3) |     |
        -------------
        */

        for(int j=0;j<n;j++){
            one=minimumArea(grid,0,m-1,j+1,n-1);
            for(int i=0;i<m;i++){
                two=minimumArea(grid,0,i,0,j);
                three=minimumArea(grid,i+1,m-1,0,j);
                ans=min(ans,one+two+three);
            }
        }

        
        /*
        4th possibility
        -------------
        | (2) | (3) |
        |     |     |
        ------------
        |           |
        |    (1)    |
        -------------
        */
        for(int i=0;i<m;i++){
            one=minimumArea(grid,i+1,m-1,0,n-1);
            for(int j=0;j<n;j++){
                two=minimumArea(grid,0,i,0,j);
                three=minimumArea(grid,0,i,j+1,n-1);
                ans=min(ans,one+two+three);
            }
        }


        /*
        5th possibility
        -------------
        |    (1)    |
        -------------
        |    (2)    |
        -------------
        |    (3)    |
        -------------
        */
        for(int i=0;i<m;i++){
            for(int k=i+1;k<m;k++){
                one=minimumArea(grid,0,i,0,n-1);
                two=minimumArea(grid,i+1,k,0,n-1);
                three=minimumArea(grid,k+1,m-1,0,n-1);
                ans=min(ans,one+two+three);
            }
        }


        /*
        6th possibility
        -------------
        |   |   |   |
        |   |   |   |
        |(1)|(2)|(3)|
        |   |   |   |
        |   |   |   |
        -------------
        */  
        for(int j=0;j<n;j++){
            for(int k=j+1;k<n;k++){
                one=minimumArea(grid,0,m-1,0,j);
                two=minimumArea(grid,0,m-1,j+1,k);
                three=minimumArea(grid,0,m-1,k+1,n-1);
                ans=min(ans,one+two+three);
            }
        }

        return ans;

    }

       long long minimumArea(vector<vector<int>>& grid, int st_i, int en_i, int st_j, int en_j) {
        long long top = -1, bottom = -1, left = -1, right = -1;
        
        for(int i=st_i;i<=en_i;i++)
        {
            for(int j=st_j;j<=en_j;j++)
            {
                if(grid[i][j]==1)
                {
                    if(top==-1) top=i;
                    bottom=i;
                }
            }
        } // n*m
        
        for(int i=st_j;i<=en_j;i++)
        {
            for(int j=st_i;j<=en_i;j++)
            {
                if(grid[j][i]==1)
                {
                    if(left==-1) left=i;
                    right=i;
                }
            }
        } //n*m
        
        long long area = (right-left+1)*(bottom-top+1);
        return area;
    }
};