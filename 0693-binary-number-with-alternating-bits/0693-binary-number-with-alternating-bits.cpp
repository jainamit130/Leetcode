class Solution {
public:
    bool hasAlternatingBits(int n) {
        // ends with 0 or ends with 1
        int next1 = 0;
        int next2 = 1;
        while(n) {
            if(next1!=-1 && next1==(n&1)) next1=!next1;
            else next1=-1;
            if(next2!=-1 && next2==(n&1)) next2=!next2;
            else next2=-1;
            if(next1==-1 && next2==-1) return false;
            n=n>>1;
        }
        return true;
    }
};