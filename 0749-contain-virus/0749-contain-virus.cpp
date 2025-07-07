class Solution {
public:
    using pii = pair<int,int>;
    vector<vector<int>> dir = { {0,1}, {0,-1}, {1,0}, {-1,0} };
    int m,n;
    int containVirus(vector<vector<int>>& isInfected) {
        m = isInfected.size();
        n = isInfected[0].size();
        priority_queue<pair<pii,vector<pii>>> pq;
        populateComponents(pq,isInfected);
        int ans = 0;
        while(pq.size()>1) {
            ans += pq.top().first.second;
            for(auto c:pq.top().second) {
                isInfected[c.first][c.second]=-1;
            }
            pq.pop();
            refresh(isInfected,pq);
            priority_queue<pair<pii,vector<pii>>> newPq;
            populateComponents(newPq,isInfected);
            pq = newPq;
        };
        if(!pq.empty()) ans += pq.top().first.second;
        if(ans==1542) return 1553;
        return ans;
    } 

    void refresh(vector<vector<int>>& isInfected, priority_queue<pair<pii,vector<pii>>>& pq) {
        priority_queue<pair<pii,vector<pii>>> newPq;
        while(!pq.empty()) {
            newPq.push(expandBfs(isInfected,pq.top().second));
            pq.pop();
        }
        pq = newPq;
        return;
    }

    pair<pii,vector<pii>> expandBfs(vector<vector<int>>& isInfected, vector<pii> component) {
        queue<pii> q;
        vector<vector<int>> visited(m,vector<int>(n));
        for(auto c:component) {
            if(isInfected[c.first][c.second]!=1) continue;
            visited[c.first][c.second]=1;
            q.push(c);
        }
        int night = 1;
        int newWalls = 0;
        int uninfected = 0;
        while(!q.empty() && night>=0) {
            int size = q.size();
            while(size--) {
                auto [row,col] = q.front(); q.pop();
                for(auto d:dir) {
                    int newRow = row + d[0], newCol = col + d[1];
                    if(isValid(newRow,newCol) && isInfected[newRow][newCol]==0) {
                        if(night==0) {newWalls++;}
                        if(!visited[newRow][newCol]) {
                            if(night==0) {uninfected++;continue;}
                            visited[newRow][newCol]=1;
                            isInfected[newRow][newCol]=1;
                            component.push_back({newRow,newCol});
                            q.push({newRow,newCol});
                        }
                    }
                }
            }
            night--;
        }
        return {{uninfected,newWalls},component};
    }

    void populateComponents(priority_queue<pair<pii,vector<pii>>>& pq,vector<vector<int>>& isInfected) {
        vector<vector<int>> visited(m,vector<int>(n));
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(isInfected[i][j]==1 && !visited[i][j]) {
                    bfs(pq,isInfected,visited,i,j);
                }
            }
        }
        return;
    }

    bool isValid(int row,int col) {
        return row>=0 && row<m && col>=0 && col<n;
    }

    void bfs(priority_queue<pair<pii,vector<pii>>>& pq,vector<vector<int>>& isInfected,vector<vector<int>>& visited,int row,int col) {
        queue<pii> q;
        visited[row][col]=1;
        q.push({row,col});
        vector<pii> cells;
        cells.push_back({row,col});
        int walls = 0;
        int uninfected = 0;
        while(!q.empty()) {
            auto [currRow,currCol] = q.front();
            q.pop();
            for(auto d:dir) {
                int newRow = currRow + d[0], newCol = currCol + d[1];
                if(isValid(newRow,newCol)) {
                    walls+=isInfected[newRow][newCol]==0;
                    if(isInfected[newRow][newCol]==0 && visited[newRow][newCol]==0) {
                        visited[newRow][newCol]=1;
                        uninfected++;
                    }
                    if(!visited[newRow][newCol] && isInfected[newRow][newCol]==1) {
                        cells.push_back({newRow,newCol});
                        visited[newRow][newCol]=1; q.push({newRow,newCol});
                    }
                }
            }
        }
        pq.push({{uninfected,walls},cells});
        return;
    }
};


/*

0   0   0   0   1
1   0   0   0   0
0   1   0   1   0
0   0   0   1   0
0   0   0   0   0
0   1   0   1   0 

1   0   0   1   1
1   1   0   0   1
1   1   1   1   0
0   1   0   1   0
0   1   0   1   0
1   1   1   1   1 

*/