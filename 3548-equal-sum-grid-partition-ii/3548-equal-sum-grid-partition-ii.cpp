class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<long long> row(m);
        vector<long long> col(n);

        unordered_map<long long,pair<int,int>> rowSec;
        unordered_map<long long,pair<int,int>> rowOtherSec;

        unordered_map<long long,pair<int,int>> colSec;
        unordered_map<long long,pair<int,int>> colOtherSec;

        // just a single row when i==0
        unordered_map<long long,pair<int,int>> rowSecJust1;
        // just a single row when i==m-1
        unordered_map<long long,pair<int,int>> rowOtherSecJust1;

        // just a single col when j==0
        unordered_map<long long,pair<int,int>> colSecJust1;
        // just a single col when j==n-1
        unordered_map<long long,pair<int,int>> colOtherSecJust1;

        long long sum = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(i==21694) cout<<grid[i][j]<<" ";
                sum +=grid[i][j];
                row[i] +=grid[i][j];
                col[j] +=grid[i][j];

                if(rowSec.find(grid[i][j])==rowSec.end()) rowSec[grid[i][j]] = {INT_MAX,INT_MIN};
                if(rowOtherSec.find(grid[i][j])==rowOtherSec.end()) rowOtherSec[grid[i][j]] = {INT_MAX,INT_MIN};
                if(colSec.find(grid[i][j])==colSec.end()) colSec[grid[i][j]] = {INT_MAX,INT_MIN};
                if(colOtherSec.find(grid[i][j])==colOtherSec.end()) colOtherSec[grid[i][j]] = {INT_MAX,INT_MIN};

                rowSec[grid[i][j]] = { min(rowSec[grid[i][j]].first,i), max(rowSec[grid[i][j]].second,i) };
                rowOtherSec[grid[i][j]] = { min(rowOtherSec[grid[i][j]].first,i), max(rowOtherSec[grid[i][j]].second,i) };
                colSec[grid[i][j]] = { min(colSec[grid[i][j]].first,j), max(colSec[grid[i][j]].second,j) };
                colOtherSec[grid[i][j]] = { min(colOtherSec[grid[i][j]].first,j), max(colOtherSec[grid[i][j]].second,j) };


                if(i==0 && (j==0 || j==n-1)) rowSecJust1[grid[i][j]] = { min(rowSecJust1[grid[i][j]].first,i), max(rowSecJust1[grid[i][j]].second,i) };
                if(i==m-1 && (j==0 || j==n-1)) rowOtherSecJust1[grid[i][j]] = { min(rowOtherSecJust1[grid[i][j]].first,i), max(rowOtherSecJust1[grid[i][j]].second,i) };
                if(j==0 && (i==0 || i==m-1)) colSecJust1[grid[i][j]] = { min(colSecJust1[grid[i][j]].first,j), max(colSecJust1[grid[i][j]].second,j) };
                if(j==n-1 && (i==0 || i==m-1)) colOtherSecJust1[grid[i][j]] = { min(colOtherSecJust1[grid[i][j]].first,j), max(colOtherSecJust1[grid[i][j]].second,j) };

            }
        }
        // horizontal cut
        long long ans = LLONG_MAX;
        long long rowSum = 0;
        for(int i=0;i<row.size();i++) {
            rowSum += row[i];
            long long otherSec = sum - rowSum;
            long long diff = llabs(rowSum - otherSec);
            // rowSum is equal to other section sum
            if(otherSec==rowSum) return true;
            // other section sum is higher
            else if(otherSec>rowSum) {
                if(rowOtherSec.find(diff)!=rowOtherSec.end() && rowOtherSec[diff].second>=i+1) {
                    // check for single row in bottom section
                    if(i==m-2 && rowOtherSecJust1.find(diff)==rowOtherSecJust1.end()) continue;  
                    // check for single column case
                    if(n==1 && rowOtherSec[diff].second!=m-1 && rowOtherSec[diff].second!=i+1) continue;
                    return true;
                }
            }
            // rowSec is higher 
            else {
                if(rowSec.find(diff)!=rowSec.end() && rowSec[diff].first<=i) {
                    // check for single row in upper section
                    if(i==0 && rowSecJust1.find(diff)==rowSecJust1.end()) continue;  
                    // check for single column case
                    if(n==1 && rowSec[diff].first!=0 && rowSec[diff].second!=i) continue;
                    return true;
                }
            }
        }

        // vertical cut
        long long colSum = 0;
        for(int i=0;i<col.size();i++) {
            colSum += col[i];
            long long otherSec = sum - colSum;
            long long diff = llabs(colSum-otherSec);
            // rowSum is equal to other section sum
            if(otherSec==colSum) return true;
            // other section sum is higher
            else if(otherSec>colSum) {
                if(colOtherSec.find(diff)!=colOtherSec.end() && colOtherSec[diff].second>=i+1) {
                    // check for single col in right section
                    if(i==n-2 && colOtherSecJust1.find(diff)==colOtherSecJust1.end()) continue;  
                    // check for single row case
                    if(m==1 && colOtherSec[diff].second!=n-1 && colOtherSec[diff].second!=i+1) continue;
                    return true;
                }
            }
            // rowSec is higher 
            else {
                if(colSec.find(diff)!=colSec.end() && colSec[diff].first<=i) {
                    // check for single col in left section
                    if(i==0 && colSecJust1.find(diff)==colSecJust1.end()) continue;  
                    // check for single row case
                    if(m==1 && colSec[diff].first!=0 && colSec[diff].second!=i) continue;
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