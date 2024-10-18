class Solution {
public:
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
    using pii = pair<int,int>;
    int cutOffTree(vector<vector<int>>& forest) {
        vector<vector<int>> indexes;
        for(int i=0;i<forest.size();i++){
            for(int j=0;j<forest[0].size();j++){
                if(forest[i][j]>1){
                    indexes.push_back({forest[i][j],i,j});
                }
            }
        }
        sort(indexes.begin(),indexes.end());
        pii start={0,0};
        int ans=0;
        int i=0;
        while(i<indexes.size()){
            pii end={indexes[i][1],indexes[i][2]};
            int steps = shortestPath(forest,start,end);
            if(steps==-1){
                return -1;
            }
            ans+=steps;
            start=end;
            i++;
        }
        return ans;
    }


    int shortestPath(vector<vector<int>>& forest,pii& start, pii& end){
        queue<pii> q;
        q.push(start);
        int level = 0;
        vector<vector<int>> visited(forest.size(),vector<int>(forest[0].size()));
        visited[start.first][start.second]=1;
        while(!q.empty()){
            int size= q.size();
            while(size){
                pii index = q.front();

                q.pop();
                size--;

                if(index==end){
                    return level;
                }

                for(auto d:dir){
                    pii newIndex = {index.first+d[0],index.second+d[1]};
                    if(isValid(newIndex,forest.size(),forest[0].size()) && forest[newIndex.first][newIndex.second]!=0 && visited[newIndex.first][newIndex.second]==0){
                        visited[newIndex.first][newIndex.second]=1;
                        q.push(newIndex);
                    }
                }
            }
            level++;
        }
        return -1;
    }

    bool isValid(pii& index,int m,int n){
        if(index.first>=0 && index.second>=0 && index.first<m && index.second<n){
            return true;
        }
        return false;
    }
};


/*


54581641    64080174    24346381    69107959
86374198    61363882    68783324    79706116
0


1           64080174    24346381    69107959
86374198    61363882    68783324    79706116
2


1           64080174    1           69107959
86374198    61363882    68783324    79706116
4


1           64080174    1           69107959
86374198    1           68783324    79706116
4


1           64080174    1           69107959
86374198    1           1           79706116
5


1           64080174    1           1
86374198    1           1           79706116
7


1           64080174    1           1
86374198    1           1           1
8


1           64080174    1           1
1           1           1           1
11


1           1           1           1
1           1           1           1
13

*/