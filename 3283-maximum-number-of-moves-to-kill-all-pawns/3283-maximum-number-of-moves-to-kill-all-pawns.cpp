class Solution {
public:
    vector<vector<int>> dir={{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
    int maxMoves(int kx, int ky, vector<vector<int>>& positions) {
        int n=positions.size();
        vector<vector<vector<int>>> leastMoves(n+1,vector<vector<int>>(50,vector<int>(50,INT_MAX)));
        vector<vector<int>> visited(50,vector<int>(50,0));
        //bfs from knight pos to pawns
        bfs(kx,ky,visited,leastMoves,0);
        for(int i=0;i<n;i++){
            vector<vector<int>> visited(50,vector<int>(50,0));
            bfs(positions[i][0],positions[i][1],visited,leastMoves,i+1);
        }
        unordered_map<int,vector<int>> cache;
        return dp(0,positions,0,0,leastMoves,cache);
    }

    
    int dp(int index,vector<vector<int>>& positions,int isBob,long long bitMask,vector<vector<vector<int>>>& leastMoves,unordered_map<int,vector<int>>& cache){
        if(bitMask==((1<<positions.size())-1)){
            return 0;
        }

        if(cache.find(bitMask)==cache.end()){
            cache[bitMask].resize(positions.size()+1,-1);
        }

        if(cache[bitMask][index]!=-1){
            return cache[bitMask][index];
        }

        int ans;
        if(!isBob){
            ans=INT_MIN;
            for(int i=0;i<positions.size();i++){
                if(bitMask & (1 << i)){
                    continue;
                }
                ans=max(ans,leastMoves[index][positions[i][0]][positions[i][1]]+dp(i+1,positions,!isBob,bitMask|(1<<i),leastMoves,cache));
            }
        } else {
            ans=INT_MAX;
            for(int i=0;i<positions.size();i++){
                if(bitMask & (1 << i)){
                    continue;
                }
                ans=min(ans,leastMoves[index][positions[i][0]][positions[i][1]]+dp(i+1,positions,!isBob,bitMask|(1<<i),leastMoves,cache));
            }
        }
        return cache[bitMask][index]=ans;
    }

    void bfs(int x,int y,vector<vector<int>>& visited,vector<vector<vector<int>>>& leastMoves,int index){
        queue<pair<int,int>> q;
        q.push({x,y});
        leastMoves[index][x][y]=0;
        int level=1;
        visited[x][y]=1;
        while(!q.empty()){
            int size=q.size();
            while(size){
                int posX=q.front().first;
                int posY=q.front().second;
                q.pop();
                size--;
                for(int i=0;i<8;i++){
                    int newX= posX+dir[i][0];
                    int newY= posY+dir[i][1];
                    if(newX>=0 && newX<50 && newY>=0 && newY<50 && visited[newX][newY]==0){
                        visited[newX][newY]=1;
                        leastMoves[index][newX][newY]=level;
                        q.push({newX,newY});
                    }
                }
            }
            level++;
        }
        return;
    }

};