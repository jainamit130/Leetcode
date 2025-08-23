class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int one=0,two=0,three=0;
        int ans=INT_MAX;

        /*
        1st Possibility
        ------------
        |    (1)    |
        |           |
        ------------
        | (2) | (3) |
        |     |     |
        -------------

        */
        for(int i=0;i<m;i++){
            one=minimumArea(grid,0,i,0,n-1);
            for(int  j=0;j<n;j++){
                two = minimumArea(grid,i+1,m-1,0,j);
                three = minimumArea(grid,i+1,m-1,j,n-1);
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

    int minimumArea(vector<vector<int>>& grid,int startI,int endI,int startJ, int endJ) {
        int minI=INT_MAX,minJ=INT_MAX;
        int maxI=INT_MIN,maxJ=INT_MIN;
        for(int i=startI;i<=endI;i++){
            for(int j=startJ;j<=endJ;j++){
                if(grid[i][j]==1){
                    minI=min(minI,i);
                    minJ=min(minJ,j);
                    maxI=max(maxI,i);
                    maxJ=max(maxJ,j);
                }
            }
        }
        if(minI==INT_MAX || minJ==INT_MAX || maxJ == INT_MIN || maxI==INT_MIN){
            return 900;
        }
        return (maxI-minI+1)*(maxJ-minJ+1);
    }    
};

/*


2 possibilities

        -------------
        |    (1)    |
        |           |
        -------------
        |    (2)    |
        |           |
        -------------

        -------------
        |     |     |
        |     |     |
        | (1) | (2) |
        |     |     |
        |     |     |
        -------------

6 possibilities

        1st Possibility
        ------------
        |    (1)    |
        |           |
        ------------
        | (2) | (3) |
        |     |     |
        -------------
        
        
        2nd Possibility
        -------------
        |     | (2) |
        |     |     |
        | (1) -------
        |     |     |
        |     | (3) |
        -------------

        3rd Possibility
        -------------
        |     |     |
        | (2) |     |
        ------- (1) |
        |     |     |
        | (3) |     |
        -------------  


        4th possibility
        -------------
        | (2) | (3) |
        |     |     |
        ------------
        |           |
        |    (1)    |
        -------------   


        5th possibility
        -------------
        |    (1)    |
        -------------
        |    (2)    |
        -------------
        |    (3)    |
        -------------


        6th possibility
        -------------
        |   |   |   |
        |   |   |   |
        |(1)|(2)|(3)|
        |   |   |   |
        |   |   |   |
        -------------
        
*/




