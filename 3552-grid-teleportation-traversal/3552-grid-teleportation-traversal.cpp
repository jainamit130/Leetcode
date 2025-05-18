class Solution {
public:
    vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    int minMoves(vector<string>& matrix) {
        int m = matrix.size();
        int n = matrix[0].length();

        vector<vector<pair<int, int>>> portals(26);
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                char ch = matrix[i][j];
                if (ch >= 'A' && ch <= 'Z') {
                    portals[ch - 'A'].push_back({i, j});
                }
            }
        }

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        vector<bool> used(26, false); 

        auto isValid = [&](int row, int col) {
            return row >= 0 && row < m && col >= 0 && col < n && matrix[row][col] != '#';
        };

        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> q;
        q.push({0, 0, 0});
        dist[0][0] = 0;

        while (!q.empty()) {
            auto [moves, row, col] = q.top(); q.pop();

            if (row == m - 1 && col == n - 1) return moves;
            if (dist[row][col] < moves) continue;

            for (auto d : dir) {
                int newRow = row + d[0];
                int newCol = col + d[1];
                if (isValid(newRow, newCol) && dist[newRow][newCol] > moves + 1) {
                    dist[newRow][newCol] = moves + 1;
                    q.push({moves + 1, newRow, newCol});
                }
            }

            char ch = matrix[row][col];
            if (ch >= 'A' && ch <= 'Z') {
                int id = ch - 'A';
                if (!used[id]) {
                    used[id] = true;
                    for (auto &[r, c] : portals[id]) {
                        if (r == row && c == col) continue;
                        if (dist[r][c] > moves) {
                            dist[r][c] = moves;
                            q.push({moves, r, c});
                        }
                    }
                }
            }
        }

        return -1;
    }
};



// class Solution {
// public:
//     vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
//     int minMoves(vector<string>& matrix) {
//         int m = matrix.size();
//         int n = matrix[0].length();
//         vector<vector<vector<int>>> portals(26);
//         for(int i=0;i<m;i++) {
//             for(int j=0;j<n;j++)  {
//                 int ascii = matrix[i][j]-'A';
//                 if(ascii>=0 && ascii<26) {
//                     portals[ascii].push_back({i,j});
//                 }
//             }
//         }
//         vector<vector<int>> dist(m,vector<int>(n,INT_MAX)); 
//         auto isValid = [&](int row,int col) {
//             return row>=0 && row<m && col>=0 && col<n;
//         };
//         vector<int> alpha(26,0);
//         priority_queue<pair<vector<int>,vector<int>>,vector<pair<vector<int>,vector<int>>>,greater<pair<vector<int>,vector<int>>>> q;
//         q.push({{0,0,0},alpha});
//         int ans = INT_MAX;
//         dist[0][0]=0;
//         while(!q.empty()) {
//             auto [rowCol,alpha] = q.top();
//             int row = rowCol[0];
//             int col = rowCol[1];
//             int moves = rowCol[2];
//             q.pop();
//             if(dist[row][col]<moves) continue;
            
//             if(row==m-1 && col==n-1) return moves;
//             dist[row][col]=moves;
//             for(auto d:dir) {
//                 int newRow = row + d[0];
//                 int newCol = col + d[1];
//                 if(isValid(newRow,newCol)) q.push({{newRow,newCol,moves+1},{alpha}});
//             }
            
//             if(matrix[row][col]!='.' && matrix[row][col]!='#' && alpha[matrix[row][col]-'A']==0) {
//                 alpha[matrix[row][col]-'A']=1;
//                 for(int i=0;i<portals[matrix[row][col]-'A'].size();i++) {
//                     int rowTeleported = portals[matrix[row][col]-'A'][i][0];
//                     int colTeleported = portals[matrix[row][col]-'A'][i][1];
//                     if(rowTeleported==row && colTeleported==col) continue;
//                     q.push({{rowTeleported,colTeleported,moves},alpha});
//                 }
//             }
//         }
//         return -1;
//     }
// };



/*


.   A   .   .
A   A   .   .
A   .   .   .



*/