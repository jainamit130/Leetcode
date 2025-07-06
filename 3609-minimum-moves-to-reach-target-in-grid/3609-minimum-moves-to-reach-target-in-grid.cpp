class Solution {
public:
    int minMoves(int sx, int sy, int tx, int ty) {
        if(tx<sx || ty<sy) return -1;
        if(tx==sx && ty==sy) return 0;

        if(tx>ty) {
            if(tx>2*ty) {
                if(tx%2!=0) return -1;
                int subAns = minMoves(sx,sy,tx/2,ty);
                return subAns==-1? -1 : subAns + 1;
            } else {
                int subAns = minMoves(sx,sy,tx-ty,ty);
                return subAns==-1? -1 : subAns + 1;
            }
        } else if(tx<ty) {
            if(ty>2*tx) {
                if(ty%2!=0) return -1;
                int subAns = minMoves(sx,sy,tx,ty/2);
                return subAns==-1? -1 : subAns + 1;
            } else {
                int subAns = minMoves(sx,sy,tx,ty-tx);
                return subAns==-1? -1 : subAns + 1;
            }
        } else {
            if(sx==0 && sy==0 && (tx!=0 || ty!=0)) return -1;
            if(sx==0) {
                int subAns = minMoves(sx,sy,0,ty);
                return subAns==-1? -1 : subAns + 1;
            }
            if(sy==0) {
                int subAns = minMoves(sx,sy,tx,0);
                return subAns==-1? -1 : subAns + 1;
            }
        }
        return -1;
    }
};


/*


tx  ty => px    py=ty

if(tx>ty) => 
if{tx = 2*px (i want this to be true but this will only be true if
1 => px>py => tx/2 > ty => tx > 2*ty && tx is divisble by 2
)) else {
    px<py => tx-ty, ty => this the other possibility 
}

if(tx<ty) => exact opposite

if(tx==ty) => both are 0 and both sx and sy are also 0
           =>  0,ty    or    tx,0


*/