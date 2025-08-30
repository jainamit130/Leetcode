class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> boxBitMask(3,vector<int>(3));
        vector<int> row(m),col(n);
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(board[i][j]=='.') continue;
                int val = board[i][j]-'0';
                vector<int> valuesToCheck = {boxBitMask[i/3][j/3],row[i],col[j]};
                for(auto valueToCheck:valuesToCheck) {
                    if((valueToCheck>>val)&1) return false;
                }    
                boxBitMask[i/3][j/3]|=1<<val;
                row[i]|=1<<val;
                col[j]|=1<<val;
            }
        }
        return true;
    }
};


/*

2+2 = 4







*/