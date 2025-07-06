class Solution {
public:
    int minMoves(vector<string>& matrix) {
        vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        int m = matrix.size();
        int n = matrix[0].length();
        vector<vector<vector<int>>> portals(26);
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++)  {
                int ascii = matrix[i][j]-'A';
                if(ascii>=0 && ascii<26) {
                    portals[ascii].push_back({i,j});
                }
            }
        }
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX)); 
        vector<int> alpha(26,0);
        
        priority_queue<array<int,3>, vector<array<int,3>>, greater<>> q;
        q.push({0,0,0});
        dist[0][0]=0;

        while(!q.empty()) {
            auto [moves, row, col] = q.top(); q.pop();
            if(dist[row][col]<moves) continue;
            
            if(row==m-1 && col==n-1) return moves;

            for(auto& d : dir) {
                int newRow = row + d[0], newCol = col + d[1];
                if(newRow>=0 && newRow<m && newCol>=0 && newCol<n 
                   && matrix[newRow][newCol]!='#' 
                   && dist[newRow][newCol]>moves+1) {
                    dist[newRow][newCol]=moves+1;
                    q.push({moves+1, newRow, newCol});
                }
            }
            
            if(matrix[row][col] >= 'A' && matrix[row][col] <= 'Z' && alpha[matrix[row][col]-'A']==0) {
                int pid = matrix[row][col] - 'A';
                alpha[pid] = 1;
                for(const auto& p : portals[pid]) {
                    int rowTeleported = p[0], colTeleported = p[1];
                    if(rowTeleported == row && colTeleported == col) continue;
                    if(dist[rowTeleported][colTeleported] > moves) {
                        dist[rowTeleported][colTeleported] = moves;
                        q.push({moves, rowTeleported, colTeleported});
                    }
                }
            }
        }
        return -1;
    }
};



/*


.   A   .   .
A   A   .   .
A   .   .   .



*/