class neighborSum {
public:
    unordered_map<int,int> adj;
    unordered_map<int,int> diag;
    neighborSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int a=0;
                if(isValid(m,n,i+1,j)){
                    a+=grid[i+1][j];
                }
                if(isValid(m,n,i-1,j)){
                    a+=grid[i-1][j];
                }
                if(isValid(m,n,i,j+1)){
                    a+=grid[i][j+1];
                }
                if(isValid(m,n,i,j-1)){
                    a+=grid[i][j-1];
                }
                int b=0;
                if(isValid(m,n,i+1,j+1)){
                    b+=grid[i+1][j+1];
                }
                if(isValid(m,n,i-1,j+1)){
                    b+=grid[i-1][j+1];
                }
                if(isValid(m,n,i+1,j-1)){
                    b+=grid[i+1][j-1];
                }
                if(isValid(m,n,i-1,j-1)){
                    b+=grid[i-1][j-1];
                }

                adj[grid[i][j]]=a;
                diag[grid[i][j]]=b;
            }
        }
    }
    
    int adjacentSum(int value) {
        return adj[value];
    }
    
    int diagonalSum(int value) {
        return diag[value];
    }

    bool isValid(int m,int n,int i,int j){
        if(i>=0 && i<m && j>=0 && j<n){
            return true;
        }
        return false;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */