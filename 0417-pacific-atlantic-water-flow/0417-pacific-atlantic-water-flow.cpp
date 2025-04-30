class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    vector<vector<int>> ans;
    vector<vector<int>> pacific, atlantic;
    int m, n;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        bfs(heights,0,0,pacific);
        bfs(heights,m-1,n-1,atlantic);
        vector<vector<int>> ans;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(pacific[i][j]+atlantic[i][j]>=2) ans.push_back({i,j});
            }
        }

        return ans;
    }

    void bfs(vector<vector<int>>& heights,int srcRow,int srcCol,vector<vector<int>>& ocean) {
        queue<pair<int,int>> q;
        ocean.resize(m,vector<int>(n,-1));
        for(int j=0;j<n;j++) {
            q.push({srcRow,j});
            ocean[srcRow][j]=1;
        }
        for(int i=0;i<m;i++) {
            q.push({i,srcCol});
            ocean[i][srcCol]=1;
        }

        while(!q.empty()) {
            auto [row,col] = q.front();
            q.pop();
            for(auto d:dir) {
                int newRow = row + d[0];
                int newCol = col + d[1];
                if(isValid(newRow,newCol) && ocean[newRow][newCol]==-1 && heights[newRow][newCol]>=heights[row][col]) {
                    ocean[newRow][newCol]=1;
                    q.push({newRow,newCol});
                }
            }
        }
    }

    bool isValid(int row,int col) {
        return row>=0 && row<m && col>=0 && col<n;
    }
};