class Solution {
public:
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        if (m == 0) return 0;
        int n = heightMap[0].size();
        if (n == 0) return 0;

        // Min-heap (priority queue) to store {height, x, y}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        // Push all boundary cells into the heap
        for (int i = 0; i < m; ++i) {
            pq.push({heightMap[i][0], i, 0});
            pq.push({heightMap[i][n - 1], i, n - 1});
            visited[i][0] = visited[i][n - 1] = true;
        }
        
        for (int j = 1; j < n - 1; ++j) {
            pq.push({heightMap[0][j], 0, j});
            pq.push({heightMap[m - 1][j], m - 1, j});
            visited[0][j] = visited[m - 1][j] = true;
        }
        
        int maxHeight = 0, trappedWater = 0;
        
        // Process cells in the heap
        while (!pq.empty()) {
            auto cell = pq.top();
            pq.pop();
            
            int height = cell[0], x = cell[1], y = cell[2];
            maxHeight = max(maxHeight, height);
            
            // Check all 4 neighbors
            for (const auto& dir : directions) {
                int nx = x + dir[0];
                int ny = y + dir[1];
                
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    
                    // Calculate trapped water if the neighbor is lower
                    if (heightMap[nx][ny] < maxHeight) {
                        trappedWater += maxHeight - heightMap[nx][ny];
                    }
                    
                    // Push neighbor into the heap
                    pq.push({heightMap[nx][ny], nx, ny});
                }
            }
        }
        
        return trappedWater;
    }
};


// class Solution {
// public:
//     vector<vector<int>> dir={ {0,1}, {0,-1}, {1,0}, {-1,0} };
//     int trapRainWater(vector<vector<int>>& heightMap) {
//         priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
//         int m=heightMap.size();
//         int n=heightMap[0].size();
//         for(int i=1;i<m-1;i++){
//             for(int j=1;j<n-1;j++){
//                 pq.push({heightMap[i][j],i,j});
//             }
//         } 

//         vector<vector<int>> visited(m,vector<int>(n,-1)); 
//         int ans=0;
//         while(!pq.empty()){
//             queue<vector<int>> q;
//             int initialVal=pq.top()[0];
//             int borderVal=INT_MAX;
//             int count=0;
//             if(visited[pq.top()[1]][pq.top()[2]]==initialVal){
//                 pq.pop();
//                 continue;
//             }
//             q.push({pq.top()[1],pq.top()[2]});
//             pq.pop();
//             bool flag=0;
//             while(!q.empty()){
//                 int x = q.front()[0];
//                 int y = q.front()[1];
//                 q.pop();
//                 if(visited[x][y]==initialVal){
//                     continue;
//                 }
//                 count++;
//                 visited[x][y]=initialVal;
//                 for(int i=0;i<dir.size();i++){
//                     int newX=dir[i][0]+x;
//                     int newY=dir[i][1]+y;
//                     if(!isValid(newX,newY,m,n)){
//                         borderVal=INT_MAX;
//                         flag=1;
//                         continue;
//                     }
                    
//                     if(visited[newX][newY]==initialVal){
//                         continue;
//                     }

//                     if(heightMap[newX][newY]>initialVal){
//                         if(flag==0)
//                             borderVal=min(heightMap[newX][newY],borderVal);
//                         continue;
//                     } 
//                     q.push({newX,newY});
//                 }
//             }
//             if(borderVal!=INT_MAX)
//                 ans+=count*(borderVal-initialVal);
//         }
//         return ans;
//     }

//     bool isValid(int x, int y, int m, int n){
//         if(x>=0 && x<m && y>=0 && y<n){
//             return true;
//         }
//         return false;
//     }
// };


// /*
// 9   9   9   9   9   9   8   9   9   9   9
// 9   0   0   0   0   0   1   0   0   0   9   
// 9   0   0   0   0   0   0   0   0   0   9
// 9   0   0   0   0   0   0   0   0   0   9
// 9   9   9   9   9   9   9   9   9   9   9


// 26+27*7

// */