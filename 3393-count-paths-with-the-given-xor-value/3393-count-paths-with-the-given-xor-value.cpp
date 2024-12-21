class Solution {
public:
    vector<vector<vector<int>>> cache;
    int mod = 1e9+7;
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        cache.resize(grid.size()+1,vector<vector<int>>(grid[0].size()+1,vector<int>(16,-1)));
        return solve(0,0,0,grid,k);
    }

    int solve(int row,int col,int xors,vector<vector<int>>& grid,int& k) {
        if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size()) {
            return 0;
        }

        if(row==grid.size()-1 && col==grid[0].size()-1) {
            if((xors^grid[row][col])==k) {
                return 1;
            } else {
                return 0;
            }
        }

        if(cache[row][col][xors]!=-1) {
            return cache[row][col][xors];
        }

        return cache[row][col][xors]=(solve(row+1,col,grid[row][col]^xors,grid,k)%mod+solve(row,col+1,grid[row][col]^xors,grid,k)%mod)%mod;
    }
};