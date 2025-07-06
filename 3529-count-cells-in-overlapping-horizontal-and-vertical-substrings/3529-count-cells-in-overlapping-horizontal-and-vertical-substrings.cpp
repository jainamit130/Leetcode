class Solution {
public:
    int m,n;
    int countCells(vector<vector<char>>& grid, string pattern) {
        vector<int> lis = getLIS(pattern);
        m = grid.size();
        n = grid[0].size();
        int k = 0;
        vector<vector<int>> hor(m,vector<int>(n));
        vector<vector<int>> ver(m,vector<int>(n));

        matchPattern(grid,pattern,lis,hor,1);
        matchPattern(grid,pattern,lis,ver,0);

        int ans = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(ver[i][j]+hor[i][j]>=2) ans++;
            }
        }
        return ans;
    }

    void matchPattern(vector<vector<char>>& grid,string pattern,vector<int>& lis,vector<vector<int>>& container,bool isHor) {
        int k = 0;
        for(int i=0; isHor? i<m: i<n ;i++) {
            for(int j=0; isHor? j<n: j<m; j++) {
                char ch = isHor ? grid[i][j]:grid[j][i];
                if(ch==pattern[k]) {
                    k++;
                    int& con = isHor? container[i][j] : container[j][i];
                    if(k==pattern.length()) { con=pattern.length(); k=lis[k-1]; }
                } else {
                    while(k-1>=0 && ch!=pattern[k]) k=lis[k-1];
                    if(ch==pattern[k]) k++;
                }
            }
        }
        normalizeContainer(container,isHor);
    }

    void normalizeContainer(vector<vector<int>>& container,bool isHor) {
        int count = 0;
        for(int i=isHor?m-1:n-1;i>=0;i--) {
            for(int j=isHor?n-1:m-1;j>=0;j--) {
                int& val = isHor?container[i][j]:container[j][i];
                if(val!=0) count=val;
                if(count>0) val=1;
                count--;
            }
        }
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