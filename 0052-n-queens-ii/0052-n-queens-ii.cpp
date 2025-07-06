class Solution {
public:
    int totalNQueens(int n) {
        vector<int> rows(n);
        vector<int> cols(n);
        vector<vector<int>> diagonals(n,vector<int>(n));
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=solve(n,n,0,i,rows,cols,diagonals);
        }
        return ans/n;
    }

    int solve(int size,int n,int row,int col,vector<int> rows,vector<int> cols,vector<vector<int>> diagonals){
        if(n==0){
            return 1;
        }

        if(row>=size)
            return 0;

        if(rows[row] || cols[col] || diagonals[row][col]){
            return 0;
        }

        rows[row]=1;
        cols[col]=1;
        int i=row;
        int j=col;
        while(i<size && j<size){
            diagonals[i][j]=1;
            i++;j++;
        }

        i=row;
        j=col;
        while(i<size && j>=0){
            diagonals[i][j]=1;
            i++;j--;
        }
        int ans=0;

        for(int i=0;i<size;i++){
            ans+=solve(size,n-1,row+1,i,rows,cols,diagonals);
        }
        rows[row]=0;
        cols[col]=0;
        i=row;
        j=col;
        while(i<size && j<size){
            diagonals[i][j]=0;
            i++;j++;
        }

        i=row;
        j=col;
        while(i<size && j>=0){
            diagonals[i][j]=0;
            i++;j--;
        }
        return ans; 
    }

    void printRow(vector<int>& vec){
        cout<<"Vect: "<<endl;
        for(int i=0;i<vec.size();i++){
            cout<<vec[i]<<endl;
        }
        cout<<endl;
    }

    void printCol(vector<int>& vec){
        cout<<"Vect: "<<endl;
        for(int i=0;i<vec.size();i++){
            cout<<vec[i]<<" ";
        }
        cout<<endl;
    }

    void printDiag(vector<vector<int>>& diagonals){
        cout<<"Diag: "<<endl;
        for(int i=0;i<diagonals.size();i++){
            for(int j=0;j<diagonals[0].size();j++){
                cout<<diagonals[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
};