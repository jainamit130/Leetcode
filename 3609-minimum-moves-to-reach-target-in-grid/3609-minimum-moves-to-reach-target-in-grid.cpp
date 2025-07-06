class Solution {
public:
    int minMoves(int sx, int sy, int tx, int ty) {
        if(tx==sx && ty==sy) return 0;
        if(tx<sx || ty<sy) return 1e9+1;

        int ans = INT_MAX;
        if(tx>=2*ty) ans = min(ans,1+minMoves(sx,sy,tx/2,ty));
        else if(ty>=2*tx) ans = min(ans,1+minMoves(sx,sy,tx,ty/2));
        else if(tx>=ty) ans = min(ans,1+minMoves(sx,sy,tx-ty,ty));
        else if(ty>=tx) ans = min(ans,1+minMoves(sx,sy,tx,ty-tx));
        return ans>=1e9+1?-1:ans; 
    }
};