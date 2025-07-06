class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        vector<long long> col(grid[0].size());
        vector<long long> row(grid.size());
        long long sum = 0;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) { 
                sum += grid[i][j];
                row[i] += grid[i][j];
                col[j] += grid[i][j];
            }
        }

        long long rowSum = 0;
        for(int i=0;i<row.size();i++) {
            rowSum += row[i];
            if(rowSum == sum-rowSum) return true;   
        }

        long long colSum = 0;
        for(int i=0;i<col.size();i++) {
            colSum += col[i];
            if(colSum == sum-colSum) return true;   
        }
        
        return false;
    }
};