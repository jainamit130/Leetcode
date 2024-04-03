class Solution {
public:
    vector<pair<int,int>> directions={{0,1},{0,-1},{1,0},{-1,0}};
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(word[0]==board[i][j]){
                    if(searchInBoard(i,j,board,word,0))
                        return true;
                }
            }
        }
        return false;
    }

    bool searchInBoard(int r,int c,vector<vector<char>>& board,string word,int wordIndex){
        if(wordIndex==word.length())
            return true;

        if(r<0 || r>=board.size() || c<0 || c>=board[0].size() || board[r][c]!=word[wordIndex])
            return false;

        bool searchResult=false;
        for(auto d:directions){
            char ch=board[r][c];
            board[r][c]='#';
            searchResult|=searchInBoard(r+d.first,c+d.second,board,word,wordIndex+1);
            board[r][c]=ch;
        }
        return searchResult;
    }
};



/*
ABCESEEEFS


A   B   C   E
S   F   E   S
A   D   E   E   

00
01
02
03
04
02
13
14
12
13
11
22
23
24
23
33
13
21
32


*/