class Solution {
public:
    bool canAliceWin(int n) {
        bool isAliceTurn = true;
        int s = 10;
        while(s>0) {
            n-=s;
            if(n<0){
                return !isAliceTurn;
            }
            isAliceTurn=!isAliceTurn;
            s--;
        }
        return true;
    }
};