class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        vector<vector<int>> mp={{0,1},{0,-1},{1,0},{-1,0}};
        vector<vector<bool>> visited(n,vector<bool>(m));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,0,0});
        while(!pq.empty()){
            int weight=pq.top()[0];
            int row=pq.top()[1];
            int col=pq.top()[2];
            pq.pop();
            if(visited[row][col])
                continue;
            visited[row][col]=true;
            if(row==n-1 && col==m-1)
                return weight;
            for(int k=0;k<mp.size();k++){
                int nR=row+mp[k][0];
                int nC=col+mp[k][1];
                if(nR<0 || nC>=m || nC<0 || nR>=n || visited[nR][nC])
                    continue;
                int diffHeight=abs(heights[row][col]-heights[nR][nC]);
                int temp=max(diffHeight,weight);
                pq.push({temp,nR,nC});
            }
        }
        return 0;
    }
};