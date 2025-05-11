class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        long long sum = 0;
        vector<long long> row(m);
        vector<long long> col(n); 

        unordered_map<int,pair<int,int>> rowSet;
        unordered_map<int,pair<int,int>> rowSetOtherSec;

        unordered_map<int,pair<int,int>> colSet;
        unordered_map<int,pair<int,int>> colSetOtherSec;

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                row[i]+=grid[i][j];
                col[j]+=grid[i][j];
                sum += grid[i][j];

                if(rowSet.find(grid[i][j])==rowSet.end()) rowSet[grid[i][j]] = {INT_MAX,INT_MIN};
                if(rowSetOtherSec.find(grid[i][j])==rowSetOtherSec.end()) rowSetOtherSec[grid[i][j]] = {INT_MAX,INT_MIN}; 
                if(colSet.find(grid[i][j])==colSet.end()) colSet[grid[i][j]] = {INT_MAX,INT_MIN}; 
                if(colSetOtherSec.find(grid[i][j])==colSetOtherSec.end()) colSetOtherSec[grid[i][j]] = {INT_MAX,INT_MIN}; 

                if(!(i==0 && j!=0 && j!=n-1)) rowSet[grid[i][j]] = { min(rowSet[grid[i][j]].first,i),
                                                                     max(rowSet[grid[i][j]].second,i) };
                if(!(j==0 && i!=0 && i!=m-1)) colSet[grid[i][j]] = { min(colSet[grid[i][j]].first,j),
                                                                     max(colSet[grid[i][j]].second,j) };
         
                if(!(i==m-1 && j!=0 && j!=n-1)) rowSetOtherSec[grid[i][j]] = { min(rowSetOtherSec[grid[i][j]].first,i),
                                                                               max(rowSetOtherSec[grid[i][j]].second,i) };
                if(!(j==n-1 && i!=0 && i!=m-1)) colSetOtherSec[grid[i][j]] = { min(colSetOtherSec[grid[i][j]].first,j),
                                                                               max(colSetOtherSec[grid[i][j]].second,j) };
            }
        }

        // horizontal cut
        long long rowSum = 0;
        for(int i=0;i<row.size();i++) {
            rowSum += row[i];
            long long otherSec = sum - rowSum;
            long long diff = rowSum - otherSec;
            if(diff == 0) return true;
            // other sec is higher
            else if(diff < 0) {
                long long lookup = abs(diff);
                // should be present in otherSec 
                if(rowSetOtherSec.find(lookup)!=rowSetOtherSec.end() && rowSetOtherSec[lookup].second>=i+1) {
                    if(n==1 && rowSetOtherSec[lookup].second!=m-1 && rowSetOtherSec[lookup].second!=i+1) continue;
                    return true;
                }
            }
            // rowSec is higher
            else {
                long long lookup = diff;
                // should be present in rowSec 
                if(rowSet.find(lookup)!=rowSet.end() && rowSet[lookup].first<=i) {
                    if(n==1 && rowSet[lookup].first!=0 && rowSet[lookup].first!=i) continue;
                    return true;
                }
            }
        }

        // vertical cut
        long long colSum = 0;
        for(int i=0;i<col.size();i++) {
            colSum += col[i];
            long long otherSec = sum - colSum;
            long long diff = colSum - otherSec;
            if(diff == 0) return true;
            // other sec is higher
            else if(diff < 0) {
                long long lookup = abs(diff);
                // should be present in otherSec 
                if(colSetOtherSec.find(lookup)!=colSetOtherSec.end() && colSetOtherSec[lookup].second>=i+1) {
                    if(m==1 && colSetOtherSec[lookup].second!=n-1 && colSetOtherSec[lookup].second!=i+1) continue;
                    return true;
                }
            }
            // colSum is higher
            else {
                long long lookup = diff;
                // should be present in colSec 
                if(colSet.find(lookup)!=colSet.end() && colSet[lookup].first<=i) {
                    if(m==1 && colSet[lookup].first!=0 && colSet[lookup].first!=i) continue;
                    return true;
                }
            }
        }

        return false;
    }
};

/*

4   1   8 => 13
 
3   2   6 => 11


*/