class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<int> mp(n);
        vector<vector<int>> edgeMat(n,vector<int>(n,0));
        for(auto edge:edges) {
            mp[edge[0]-1]++;
            mp[edge[1]-1]++;
            edgeMat[edge[0]-1][edge[1]-1] = 1;
            edgeMat[edge[1]-1][edge[0]-1] = 1;
        }
        int ans = n*n;
        for(int i=0;i<n-2;i++) {
            for(int j=i+1;j<n-1;j++) {
                if(edgeMat[i][j]==0) continue;
                for(int k=j+1;k<n;k++) {
                    if(edgeMat[i][k] && edgeMat[j][k]) ans = min(ans,mp[i]+mp[j]+mp[k]-6);
                }
            }
        }
        return ans==(n*n) ? -1 : ans;
    }
};