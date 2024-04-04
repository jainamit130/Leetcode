class Solution {
public:
    int ans=INT_MAX;
    vector<vector<int>> directions={{-1,0},
                              {0,-1},     {0,1},
                                    {1,0}};
    vector<vector<int>> goal={{1,2,3},{4,5,0}};
    int slidingPuzzle(vector<vector<int>>& board) {
        unordered_map<int,int> stateMap;
        vector<vector<int>> visited(2,vector<int>(3,0));
        //Get Position of Zero
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==0){
                    dfs(i,j,board,0,stateMap);
                }
            }
        }
        return stateMap.find(123450) == stateMap.end() ? -1 : stateMap[123450];
    }

    int boardValue(vector<vector<int>> board){
        int value=0;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                value=value*10+board[i][j];
            }
        }
        return value;
    }

    bool isValid(int r,int c){
        if(r<0 || r>=2 || c>=3 || c<0)
            return false;
        return true;
    }

    void dfs(int r,int c,vector<vector<int>>& board,int moves,unordered_map<int,int>& stateMap){
        if(!isValid(r,c))
            return;

        int boardVal=boardValue(board);
        if(stateMap.find(boardVal)!=stateMap.end() && stateMap[boardVal]<moves)
            return;

        stateMap[boardVal]=moves;
        if (boardVal == 123450)  return;
        for(auto d:directions){
            int nr=r+d[0];
            int nc=c+d[1];
            //swap
            if(isValid(nr,nc)){
                board[r][c]=board[nr][nc];
                board[nr][nc]=0;
            }
            dfs(nr,nc,board,moves+1,stateMap);
            if(isValid(nr,nc)){
                board[nr][nc]=board[r][c];
                board[r][c]=0;
            }
        }
        return;
    }
};






/*

1   2   3
5   4
...
1   2   3
5       4

1   3   4
5       2

1   4   2
5   3

4   2   3
    5   1

2   3   1
4   5    

*/