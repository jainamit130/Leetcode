class Solution {
public:
    bool isPrintable(vector<vector<int>>& target) {
        unordered_map<int,vector<int>> maxMinRow;
        unordered_map<int,vector<int>> maxMinCol;
        int maxColor = 0;
        for(int i=0;i<target.size();i++) {
            for(int j=0;j<target[0].size();j++) {
                int color = target[i][j]-1;
                if(maxMinRow.find(color)==maxMinRow.end()) maxMinRow[color] = {INT_MAX,INT_MIN};
                if(maxMinCol.find(color)==maxMinCol.end()) maxMinCol[color] = {INT_MAX,INT_MIN};
                maxMinRow[color] = {min(maxMinRow[color][0],i),max(maxMinRow[color][1],i)};
                maxMinCol[color] = {min(maxMinCol[color][0],j),max(maxMinCol[color][1],j)};
                maxColor = max(maxColor, target[i][j]);
            } 
        }
        int colorCount = maxMinCol.size();
        vector<vector<int>> adj(maxColor);
        vector<int> degree(maxColor);
        queue<int> q;
        for(int color=0;color<maxColor;color++) {
            if(maxMinRow.find(color)==maxMinRow.end()) continue;
            for(int i=maxMinRow[color][0];i<=maxMinRow[color][1];i++) {
                for(int j=maxMinCol[color][0];j<=maxMinCol[color][1];j++) {
                    int currColor = target[i][j]-1;
                    if(currColor!=color) {
                        adj[currColor].push_back(color);
                        degree[color]++;
                    }
                }
            }
            if(degree[color]==0) {
                q.push(color);
            }
        }
        while(!q.empty()) {
            int color = q.front();
            q.pop();
            colorCount--;
            for(auto neigh:adj[color]) {
                degree[neigh]--;
                if(!degree[neigh]) {
                    q.push(neigh);
                }
            }
        }
        return colorCount==0;
    }
};



/*

6   2   2   5

2   2   2   5

2   2   2   5

4   3   3   4



5   3   
        6   4   
                2


1   2   1
2   1   2
1   2   1



2   9   15  15  15  15
8   9   15  15  28  28
30  30  30  30  30  30
29  9   24  24  28  28



1   1   1   1
1   2   2   1
1   2   2   1
1   1   1   1

*/