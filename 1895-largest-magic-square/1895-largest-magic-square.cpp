class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        vector<vector<int>> prefix(grid.size()+1,vector<int>(grid[0].size()+1,0));
        vector<vector<int>> prefixRightDiagonals(grid.size()+1,vector<int>(grid[0].size()+1,0));
        int ROWS=grid.size(),COLS=grid[0].size();
        for(int i=1;i<=grid.size();i++){
            for(int j=1;j<=grid[0].size();j++){
                prefix[i][j]=prefix[i-1][j]+prefix[i][j-1]+grid[i-1][j-1]-prefix[i-1][j-1];
                prefixRightDiagonals[ROWS-i][j]=prefixRightDiagonals[ROWS-i+1][j-1]+grid[ROWS-i][j-1];
            }
        }
        int ans=1;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                int leftD=0;
                for(int k=0;k+i<grid.size() && k+j<grid[0].size();k++){
                    leftD+=grid[i+k][j+k];
                    // int benchmarkSum=prefix[i+k+1][j+k+1]-prefix[i][j+k+1]-prefix[i+k+1][j+k]+prefix[i][j+k];
                    int rightD=0;
                    bool flag=1;
                    for(int l=0;l<=k;l++){
                        rightD+=grid[i+l][j+k-l];
                        int benchmarkSumRow=prefix[i+l+1][j+k+1]-prefix[i+l][j+k+1]-prefix[i+l+1][j]+prefix[i+l][j];
                        int benchmarkSumCol=prefix[i+k+1][j+l+1]-prefix[i+k+1][j+l]-prefix[i][j+l+1]+prefix[i][j+l];
                        // cout<<" leftD : "<<leftD<<" : "<<i+l<<","<<j+k<<"->"<<benchmarkSumCol<<" && "<<i+k<<","<<j+l<<"->"<<benchmarkSumRow<<" && "<<i+l<<","<<j+k-l<<endl;
                        // cout<<i+l+1<<","<<j+k+1<<"->"<<prefix[i+l+1][j+k+1]<<" - "<<i+l+1<<","<<j<<"->"<<prefix[i+l+1][j]<<" - "<<i+1<<","<<j+k+1<<"->"<<prefix[i+1][j+k+1]<<" + "<<i+1<<" "<<j<<"->"<<prefix[i+1][j]<<endl;
                        if(leftD==benchmarkSumRow && leftD==benchmarkSumCol)
                            continue;
                        else {
                            flag=0;
                            break;
                        }
                    }
                    if(flag==1 && leftD==rightD){
                        ans=max(ans,k+1);
                    }
                }
            }
        }
        return ans;
    }
};

/*
0   3
1   4


0   7   1   4   5   6
0   2   5   1   6   4
0   1   5   4   3   2
0   1   2   7   3   4
0   0   0   0   0   0

0   0   0   0   0   0
0   7   8   12  17  23
0   9   15  20  31  41
0   10  21  30  44  56
0   11  24  40  57  73
i+l+1,j+k+1
i+l,j+k+1
i+l,j
i+l-1,j

7   3   10  12  18
2   6   7   12  14
1   6   6   10  5
1   2   7   3   4

*/