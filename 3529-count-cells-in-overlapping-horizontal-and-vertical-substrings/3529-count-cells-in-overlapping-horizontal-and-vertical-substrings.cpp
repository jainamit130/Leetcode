class Solution {
public:
    int countCells(vector<vector<char>>& grid, string pattern) {
        vector<int> lis = getLIS(pattern);
        int m = grid.size();
        int n = grid[0].size();
        int k = 0;
        vector<vector<int>> hor(m,vector<int>(n));
        vector<vector<int>> ver(m,vector<int>(n));
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==pattern[k]) {
                    k++;
                    if(k==pattern.length()) {hor[i][j]=pattern.length();k=lis[k-1];}
                } else {
                    while(k-1>=0 && grid[i][j]!=pattern[k]) k=lis[k-1];
                    if(grid[i][j]==pattern[k]) k++;
                }
            }
        }
        k = 0;
        for(int j=0;j<n;j++) {
            for(int i=0;i<m;i++) {
                if(grid[i][j]==pattern[k]) {
                    k++;
                    if(k==pattern.length()) {ver[i][j]=pattern.length();k=lis[k-1];}
                } else {
                    while(k-1>=0 && grid[i][j]!=pattern[k]) k=lis[k-1];
                    if(grid[i][j]==pattern[k]) k++;
                }
            }
        }

        int count = 0;
        for(int i=m-1;i>=0;i--) {
            for(int j=n-1;j>=0;j--) {
                if(hor[i][j]!=0) count=hor[i][j];
                if(count>0) hor[i][j]=1;
                count--;
            }
        }

        count = 0;
        int ans = 0;
        for(int j=n-1;j>=0;j--) {
            for(int i=m-1;i>=0;i--) {
                if(ver[i][j]!=0) count=ver[i][j];
                if(count>0) ver[i][j]=1;
                if(ver[i][j]+hor[i][j]>=2) ans++;
                count--;
            }
        }

                // for(int i=0;i<m;i++) {
        //     for(int j=0;j<n;j++) {
        //         cout<<hor[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        // cout<<endl;

        // for(int i=0;i<m;i++) {
        //     for(int j=0;j<n;j++) {
        //         cout<<ver[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        return ans;
    }

    vector<int> getLIS(string pattern) {
        int n = pattern.length();
        vector<int> lis(n);
        int i=1,j=0;
        while(i<n) {
            if(pattern[i]==pattern[j]) {
                lis[i]=j+1;
                i++;j++;
            } else {
                if(j-1>=0) j=lis[j-1];
                else i++;
            }    
        }
        return lis;
    }
};