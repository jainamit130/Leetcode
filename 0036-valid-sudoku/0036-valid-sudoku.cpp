class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
               if(board[i][j]!='.')
               {
                    if(isValid(board,i,j,board[i][j])){
                        continue;
               }    else
                        return false; 
                }
            }
        }  
        return true;      
    }

    bool isValid(vector<vector<char>>& board,int row,int col,char c){
         for(int i=0;i<9;i++){
             if(board[row][i]==c)
                {if(i!=col)
                    return false;}
            if(board[i][col]==c)
                {
                if(i!=row)
                    return false;}
            if(board[3*(row/3)+(i/3)][3*(col/3)+i%3]==c)
                {
                if((3*(row/3)+(i/3))!=row && (3*(col/3)+i%3)!=col)
                    return false;}
         }
         return true;
    }
};