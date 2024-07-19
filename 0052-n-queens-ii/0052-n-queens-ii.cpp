class Solution {
public:
    int ans=0;
    int totalNQueens(int n) {
        string s="";
        for(int i=0;i<n;i++)
            s+=".";
        vector<string> board(n,s);
        set<int> visitedCol;
        set<int> posDiag;
        set<int> negDiag;
        solve(n,board,0,visitedCol,posDiag,negDiag);
        return ans;
    }

        void solve(int n,vector<string>& board,int r,set<int>& visitedCol,set<int>& posDiag,set<int>& negDiag){
        if(r>=board.size()){
            ans++;
            return;
        }

        for(int c=0;c<n;c++){
            if(visitedCol.find(c)!=visitedCol.end() || posDiag.find(r+c)!=posDiag.end() || negDiag.find(r-c)!=negDiag.end())
                continue;

            visitedCol.insert(c);
            posDiag.insert(r+c);
            negDiag.insert(r-c);
            board[r][c]='Q';
            solve(n,board,r+1,visitedCol,posDiag,negDiag);
            visitedCol.erase(c);
            posDiag.erase(r+c);
            negDiag.erase(r-c);
            board[r][c]='.';
        }
        return;
    }
};