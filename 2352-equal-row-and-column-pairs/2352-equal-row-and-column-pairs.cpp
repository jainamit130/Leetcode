class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> columns(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                columns[j].push_back(grid[i][j]);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i]==columns[j])
                    ans++;
            }
        }
        return ans;
    }
};