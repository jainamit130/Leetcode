class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int Xr=startPos[0];
        int Yr=startPos[1];
        int Xh=homePos[0];
        int Yh=homePos[1];
        int costx=(Xr!=Xh)?rowCosts[Xh]:0;
        int costy=(Yr!=Yh)?colCosts[Yh]:0;
        for(int i=min(Xr,Xh)+1;i<max(Xr,Xh);i++){
            costx+=rowCosts[i];
        }
        for(int i=min(Yr,Yh)+1;i<max(Yr,Yh);i++){
            costy+=colCosts[i];
        }
        return costx+costy;
    }
};