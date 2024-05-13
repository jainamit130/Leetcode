class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        vector<int> nums(grid.size());
        //rows
        for(int i=0;i<grid.size();i++){
            if(grid[i][0]==0){
                nums[i]=calc(i,0,grid);
            } else {
                nums[i]=calc(i,1,grid);
            }
        }
        int sum=0;
        sum=accumulate(nums.begin(),nums.end(),sum);
        //columns
        for(int j=1;j<grid[0].size();j++){
            int wt=grid[0].size()-j-1;
            int zero=0;
            int one=0;
            for(int i=0;i<grid.size();i++){
                if(!grid[i][j]){
                    zero++;
                } else {
                    one++;
                }
            }
            if(zero>one){
                sum+=(zero-one)*pow(2,wt);
            }
        }
        return sum;
    }

    int calc(int i,int value,vector<vector<int>>& grid){
        int sum=0;
        for(int j=0;j<grid[0].size();j++){
            int wt=grid[0].size()-j-1;
            if(value==grid[i][j])
                sum+=pow(2,wt);
        }
        return sum;
    }
};


/*


0   0   1   1
1   0   1   0
1   1   0   0


1   1   0   0
1   0   1   0
1   1   0   0


1   1   1   0
1   0   0   0
1   1   1   0


1   1   1   1
1   0   0   1
1   1   1   1


*/