class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<long long> row(m);
        vector<long long> col(n);

        unordered_map<int,pair<int,int>> rowSec;
        unordered_map<int,pair<int,int>> rowOtherSec;

        unordered_map<int,pair<int,int>> colSec;
        unordered_map<int,pair<int,int>> colOtherSec;

        long long sum = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                sum +=grid[i][j];
                row[i] +=grid[i][j];
                col[j] +=grid[i][j];

                if(rowSec.find(grid[i][j])==rowSec.end()) rowSec[grid[i][j]] = {INT_MAX,INT_MIN};
                if(rowOtherSec.find(grid[i][j])==rowOtherSec.end()) rowOtherSec[grid[i][j]] = {INT_MAX,INT_MIN};
                if(colSec.find(grid[i][j])==colSec.end()) colSec[grid[i][j]] = {INT_MAX,INT_MIN};
                if(colOtherSec.find(grid[i][j])==colOtherSec.end()) colOtherSec[grid[i][j]] = {INT_MAX,INT_MIN};

                if(!(i==0 && j!=0 && j!=n-1)) rowSec[grid[i][j]] = { min(rowSec[grid[i][j]].first,i), max(rowSec[grid[i][j]].second,i) };
                if(!(i==m-1 && j!=0 && j!=n-1)) rowOtherSec[grid[i][j]] = { min(rowOtherSec[grid[i][j]].first,i), max(rowOtherSec[grid[i][j]].second,i) };
                if(!(j==0 && i!=0 && i!=m-1)) colSec[grid[i][j]] = { min(colSec[grid[i][j]].first,j), max(colSec[grid[i][j]].second,j) };
                if(!(j==n-1 && i!=0 && i!=m-1)) colOtherSec[grid[i][j]] = { min(colOtherSec[grid[i][j]].first,j), max(colOtherSec[grid[i][j]].second,j) };
            }
        }

        // horizontal cut
        long long rowSum = 0;
        for(int i=0;i<row.size();i++) {
            rowSum += row[i];
            long long otherSec = sum - rowSum;
            long long diff = abs(rowSum-otherSec);
            // rowSum is equal to other section sum
            if(otherSec==rowSum) return true;
            // other section sum is higher
            else if(otherSec>rowSum) {
                if(rowOtherSec.find(diff)!=rowOtherSec.end() && rowOtherSec[diff].second>=i+1) {
                    // check for single column case
                    if(n==1 && rowOtherSec[diff].second!=m-1 && rowOtherSec[diff].second!=i+1) return false;
                    return true;
                }
            }
            // rowSec is higher 
            else {
                if(rowSec.find(diff)!=rowSec.end() && rowSec[diff].first<=i) {
                    // check for single column case
                    if(n==1 && rowSec[diff].first!=0 && rowSec[diff].second!=i) return false;
                    return true;
                }
            }
        }


        // vertical cut
        long long colSum = 0;
        for(int i=0;i<col.size();i++) {
            colSum += col[i];
            long long otherSec = sum - colSum;
            long long diff = abs(colSum-otherSec);
            // rowSum is equal to other section sum
            if(otherSec==colSum) return true;
            // other section sum is higher
            else if(otherSec>colSum) {
                if(colOtherSec.find(diff)!=colOtherSec.end() && colOtherSec[diff].second>=i+1) {
                    // check for single row case
                    if(m==1 && colOtherSec[diff].second!=n-1 && colOtherSec[diff].second!=i+1) return true;
                    return true;
                }
            }
            // rowSec is higher 
            else {
                if(colSec.find(diff)!=colSec.end() && colSec[diff].first<=i) {
                    // check for single row case
                    if(m==1 && colSec[diff].first!=0 && colSec[diff].second!=i) return true;
                    return true;
                }
            }
        }
        return false;
    }
};



/*


Steps:

1. Create row, col array
2. Create unordered_map<int,pair<int,int>> for rowSec and rowOtherSec => have default values for a val which is not yet present as {INT_MAX,INT_MIN} 
3. Create unordered_map<int,pair<int,int>> for colSec and colOtherSec 
4. iterate through the grid and populate the above data structures
5. iterate through row array, maintain rowPrefixSum and check if it is valid or not 
6. repeat step 5 for col array
7. return false



*/