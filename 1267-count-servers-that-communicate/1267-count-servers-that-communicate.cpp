class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> col(m);
        vector<int> row(n);
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]) {
                    row[j]++;
                    col[i]++;
                } 
            }
        }
        int ans = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] && (row[j]>1 || col[i]>1)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};