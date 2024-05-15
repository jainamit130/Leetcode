class Solution {
public:
    vector<pair<int, int>> neighbor={{1,0},{0,1},{-1,0},{0,-1}};
    
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        vector<vector<int>> minSafeFactor(grid.size(),
                                          vector<int>(grid[0].size(), INT_MAX));
        queue<tuple<int, int, int>> q;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    q.push(make_tuple(i, j, 0));
                }
            }
        }
        
        bfs(grid, minSafeFactor, q);
        return modifiedBFS(minSafeFactor);
    }

    int modifiedBFS(vector<vector<int>>& minSafeFactor) {
        priority_queue<tuple<int, int, int>> pq;
        pq.push(make_tuple(minSafeFactor[0][0], 0, 0));
        
        while (!pq.empty()) {
            auto [val, r, c] = pq.top();
            pq.pop();
            
            if (r == minSafeFactor.size() - 1 && c == minSafeFactor[0].size() - 1) {
                return val;
            }
            
            for (auto& a : neighbor) {
                int nr = r + a.first;
                int nc = c + a.second;
                
                if (inValid(nr, nc, minSafeFactor.size(), minSafeFactor[0].size()) || minSafeFactor[nr][nc] == -1) {
                    continue;
                }
                
                int t = minSafeFactor[nr][nc];
                minSafeFactor[nr][nc] = -1;
                pq.push(make_tuple(min(t, val), nr, nc));
            }
        }
        
        return minSafeFactor[0][0];
    }

    void bfs(vector<vector<int>>& grid, vector<vector<int>>& minSafeFactor, queue<tuple<int, int, int>>& q) {
        while (!q.empty()) {
            int size = q.size();
            while (size) {
                auto [r, c, val] = q.front();
                q.pop();
                size--;
                
                if (inValid(r, c, grid.size(), grid[0].size()) || grid[r][c] == -1) {
                    continue;
                }
                
                if (minSafeFactor[r][c] <= val) {
                    continue;
                }
                
                minSafeFactor[r][c] = val;
                grid[r][c] = -1;
                
                for (auto& a : neighbor) {
                    q.push(make_tuple(r + a.first, c + a.second, val + 1));
                }
            }
        }
    }

    bool inValid(int row, int col, int m, int n) {
        return row < 0 || row >= m || col < 0 || col >= n;
    }
};

// class Solution {
// public:
//     vector<vector<int>> neighbor={{1,0},{0,1},{-1,0},{0,-1}};
//     int maximumSafenessFactor(vector<vector<int>>& grid) {
//         vector<vector<int>> minSafeFactor(grid.size(),
//                                           vector<int>(grid[0].size(), INT_MAX));
//         queue<vector<int>> q;
//         for (int i = 0; i < grid.size(); i++) {
//             for (int j = 0; j < grid[0].size(); j++) {
//                 if (grid[i][j] == 1) {
//                     q.push({i,j,0});
//                 }
//             }
//         }
//         bfs(grid, minSafeFactor,q);
//         // traverse(0, 0, INT_MAX, minSafeFactor);
//         return modifiedBFS(minSafeFactor);
//     }

//     int modifiedBFS(vector<vector<int>>& minSafeFactor) {
//         priority_queue<vector<int>> pq;
//         pq.push({minSafeFactor[0][0],0,0});
//         while(!pq.empty()){
//             int val=pq.top()[0];
//             int r=pq.top()[1];
//             int c=pq.top()[2];
//             pq.pop();
//             if(r==minSafeFactor.size()-1 && c==minSafeFactor[0].size()-1){
//                 return val;
//             }
//             for(auto a:neighbor){
//                 int nr=r+a[0];
//                 int nc=c+a[1];
//                 if(inValid(nr,nc,minSafeFactor.size(),minSafeFactor[0].size()) || minSafeFactor[nr][nc]==-1)
//                 continue;
//                 int t=minSafeFactor[nr][nc];
//                 minSafeFactor[nr][nc]=-1;
//                 pq.push({min(t,val),nr,nc});
//             }
//         }
//         return minSafeFactor[0][0];
//     }

//     // void traverse(int row, int col, int currMin, vector<vector<int>>& minSafeFactor) {
//     //     if (inValid(row, col, minSafeFactor.size(), minSafeFactor[0].size()))
//     //         return;

//     //     if ((row == minSafeFactor.size() - 1 &&
//     //         col == minSafeFactor[0].size() - 1)) {
//     //         currMin=min(currMin,minSafeFactor[row][col]);
//     //         ans = max(ans,currMin);
//     //         return;
//     //     }

//     //     if(minSafeFactor[row][col]==0){
//     //         ans=max(ans,0);
//     //         return;
//     //     }

//     //     traverse(row+1,col,min(currMin,minSafeFactor[row][col]),minSafeFactor);
//     //     traverse(row,col+1,min(currMin,minSafeFactor[row][col]),minSafeFactor);
//     //     return;
//     // }

//     void bfs(vector<vector<int>> grid,
//              vector<vector<int>>& minSafeFactor,queue<vector<int>>& q) {
//         while (!q.empty()) {
//             int size = q.size();
//             while (size) {
//                 int r = q.front()[0];
//                 int c = q.front()[1];
//                 int val = q.front()[2];
//                 q.pop();
//                 size--;
//                 if (inValid(r, c, grid.size(), grid[0].size()) ||
//                     grid[r][c] == -1)
//                     continue;
//                 if(minSafeFactor[r][c]<=val)
//                     continue;
//                 minSafeFactor[r][c] = val;
//                 grid[r][c] = -1;
//                 for(auto a:neighbor){
//                     q.push({r + a[0], c + a[1], val + 1});
//                 }
//             }
//         }
//     }

//     bool inValid(int row, int col, int m, int n) {
//         if (row < 0 || row >= m || col < 0 || col >= n)
//             return true;
//         return false;
//     }
// };

/*

1   0   0
0   0   0
0   0   1

BFS FROM 0,0

0   0   0
0   0   0
0   0   0

0   1   0
1   2   0
0   0   0

0   1   2
1   2   3
2   3   4


BFS FROM 2,2

4   3   2
3   2   1
2   1   0

Combined bfs (minimum of the 2 safeness factor)

0   1   2
1   2   1
2   1   0

Traversal of all paths will have maximum safeness factor as 0

Example 3

0   0   0   1
0   0   0   0
0   0   0   0
1   0   0   0

Combined BFS

3   2   1   0
2   3   2   1
1   2   3   2
0   1   2   3

Traversal - 2

3   2   1   0
2   3   2   1
1   2   3   2
0   1   2   3

pq: 
pop 3   0   0
pop 2   0   1
1   0   2
2   1   0

*/