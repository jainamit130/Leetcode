class Solution {
public:
    vector<vector<int>> dir={ {0,1}, {0,-1}, {-1,0}, {1,0} };
    int m,n;
    int minMoves(vector<string>& classRoom, int energy) {
        m = classRoom.size();
        n = classRoom[0].length();
        map<pair<int,int>,int> trashId;
        int id = 0;
        vector<int> startIndex = {-1,-1};
        for(int i=0;i<m;i++) {
            for(int j=0;j<classRoom[i].length();j++) {
               if(classRoom[i][j]=='S') startIndex = {i,j};
               else if(classRoom[i][j]=='L') trashId[{i,j}]=id++;
            }
        }

        int maxMask = (1<<id)-1;
        queue<vector<int>> q;
        q.push({energy,startIndex[0],startIndex[1],0});
        vector<vector<vector<int>>> visited(m,vector<vector<int>>(n,vector<int>(maxMask+1,-1)));
        visited[startIndex[0]][startIndex[1]][0]=energy;
        int level = 0;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int curEng = q.front()[0];
                int row = q.front()[1];
                int col = q.front()[2];
                int mask = q.front()[3];
                q.pop();

                if(mask==maxMask) return level;
                for(auto d:dir) {
                    int newRow = row + d[0];
                    int newCol = col + d[1];
                    int newEng = curEng - 1;
                    if(isValid(newRow,newCol) && classRoom[newRow][newCol]!='X') {
                        int newMask = mask;
                        if(classRoom[newRow][newCol]=='L') {
                            int id = trashId[{newRow,newCol}];
                            if((mask&(1<<id))==0) newMask = mask|(1<<id);
                        }

                        if(visited[newRow][newCol][newMask]<newEng) {
                            visited[newRow][newCol][newMask]=newEng;
                            if(classRoom[newRow][newCol]=='R') newEng = energy;
                            q.push({newEng,newRow,newCol,newMask});
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }

    bool isValid(int row,int col) {
        return row>=0 && col>=0 && row<m && col<n;
    }
};