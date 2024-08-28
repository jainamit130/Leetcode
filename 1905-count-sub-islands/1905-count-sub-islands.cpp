class Solution {
public:
    vector<vector<int>> dir={{0,1},{-1,0},{0,-1},{1,0}};
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();
        int ans = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid2[i][j] == 1) {
                    // Start with the assumption that this could be a sub-island
                    int state = 1;
                    dfs(grid1, grid2, i, j, state);
                    if(state == 1) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }

    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int row, int col, int& state) {
        // Out of bounds check
        if(row < 0 || row >= grid2.size() || col < 0 || col >= grid2[0].size()) {
            return;
        }

        // If this cell is already visited or is water in grid2
        if(grid2[row][col] != 1) {
            return;
        }

        // If this cell is not land in grid1, mark state as invalid
        if(grid1[row][col] != 1) {
            state = 0;
        }
      
        // Mark the cell as visited in grid2
        grid2[row][col] = 2;
        
        // DFS in all 4 directions
        for(auto d : dir) {
            int newR = row + d[0];
            int newC = col + d[1];
            dfs(grid1, grid2, newR, newC, state);
        }
    }
};



/*
1   0   1   0   1   0
0   1   1   1   0   1
1   0   0   0   1   1
1   0   0   0   1   0
1   1   1   1   1   0




0   1   1   1   1   1
1   1   0   1   1   1
1   0   0   1   0   1
1   1   1   1   1   1   
1   0   0   1   0   0









*/